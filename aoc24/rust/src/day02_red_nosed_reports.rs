
pub fn parse(input: &str) -> Vec<Vec<i16>> {
    let mut result: Vec<Vec<i16>> = Vec::new();

    for line in input.lines() {
        let nums = line
            .split(' ')
            .map(|x| x.parse::<i16>().unwrap())
            .collect::<Vec<_>>();
        result.push(nums);
    }

    result
}

pub fn check_increasing(list: &[i16]) -> bool {
    if list.len() < 2 { 
        return true; 
    }
    let del = list[1] - list[0];
    del >=1 && del <=3 && check_increasing(&list[1..])
}

pub fn check_decreasing(list: &[i16]) -> bool {
    if list.len() < 2 {
        return true;
    }
    let del = list[1] - list[0];
    del >= -3 && del <= -1 && check_decreasing(&list[1..]) 
}

pub fn check(list: &Vec<i16>) -> bool {
    check_increasing(list.as_slice()) || check_decreasing(list.as_slice())
}

pub fn check_and_count(lists: &Vec<Vec<i16>>) -> i64 {
    lists.iter().fold(0, |acc, list| if check(&list) { acc + 1 } else { acc })
}

#[derive(PartialEq, Eq, Copy, Clone)]
pub enum Direction {
    Increasing,
    Decreasing,
}

pub fn find_direction(list: &[i16]) -> Option<Direction> {
    let length = list.len();
    if length < 2 {
        None
    }
    else {
        let mut sign_sum: i16 = 0;
        for c in list.iter().collect::<Vec<_>>().chunks(2) {
            sign_sum += (c[1] - c[0]).signum();
        }

        match Some(sign_sum) {
            Some(x) if x < 0 => Some(Direction::Decreasing),
            Some(x) if x > 0 => Some(Direction::Increasing),
            _ => None
        }
    }
}

pub fn validate_pair(a: i16, b: i16, dir: Option<Direction>) -> bool {
    let del = b-a;
    let pass_direction = match dir {
        Some(Direction::Increasing) => del.signum() > 0,
        Some(Direction::Decreasing) => del.signum() < 0,
        None => true
    };
    let pass_magnitude = del.abs() > 0 && del.abs() < 4;

    pass_direction && pass_magnitude
}

pub fn right_fixable(list: &Vec<i16>, index: usize, dir: Option<Direction>) -> bool {
    if index == list.len()-2 {
        // end cap can always be discarded
        true
    } else {
        // try remove right
        validate_pair(list[index], list[index+2], dir)
    }
}

pub fn left_fixable(list: &Vec<i16>, index: usize, dir: Option<Direction>) -> bool {
    if index == 0 {
        // end cap can always be discarded
        true
    } else {
        // try remove left (self)
        validate_pair(list[index-1], list[index+1], dir)
    }
}

pub fn check_with_errors(list: &Vec<i16>, allowed_errors: usize) -> bool {
    // cant have a bad sequence if there is no sequence, or every pair is allowed an error
    if list.len() < 2 || list.len() - 1 < allowed_errors {
        return true;
    }

    // check if we have a direction constraint
    // must check n_allowed_errors + 2 before a fixed direction emerges
    let end = std::cmp::min(list.len(), allowed_errors+3);
    let slice = &list[0..end];
    let dir = find_direction(slice);
    if list.len() > allowed_errors+2 && dir == None {
        // too many flip flops, impossible to satisfy consistent direction constraint
        return false;
    }

    let mut remaining_errors = allowed_errors;

    let mut i = 0;
    while i < list.len()-1 {
        if !validate_pair(list[i], list[i+1], dir) {
            if remaining_errors == 0 {
                return false;
            } else if right_fixable(list, i, dir) {
                remaining_errors -= 1;
                i += 1; // is there a better way to tell an iter to skip one in rust?
            } else if left_fixable(list, i, dir) {
                remaining_errors -= 1;
            } else {
                return false;
            }
        }
        i += 1;
    }
    true
}

pub fn to_deltas(list: &Vec<i16>) -> Vec<i16> {
    let mut dels: Vec<i16> = vec![];
    for li in 0..list.len()-1 {
        dels.push(list[li+1] - list[li]);
    }
    dels
}

pub fn check_with_errors_and_count(lists: Vec<Vec<i16>>, allowed_errors: usize) -> i64 {
    lists.iter().fold(
        0, 
        |acc, list| {
            print!("{:?}", list);
            print!("    {:?}", to_deltas(list));
            let valid = check_with_errors(list, allowed_errors);
            if valid { println!("    PASS"); } else { println!(); }
            if valid { acc + 1 } else { acc }
        })
}
