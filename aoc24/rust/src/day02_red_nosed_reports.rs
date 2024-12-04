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

pub fn fuzzy_check_increasing(list: &[i16], fuzz: u8) -> bool {
    if list.len() < 2 {
        return true;
    }
    let del = list[1] - list[0];
    del >=1 && del <=3 && check_increasing(&list[1..])
}

pub fn fuzzy_check(list: &[i16], i: usize, j: usize, k: usize, fuzz: u8) -> bool {
    if list.len() < 2 {
        return true;
    }
    if k >= list.len() {
        return false
    }
    if valid_sequence(list[i], list[j], list[k]) {
        if k == list.len() - 1 {
            return true;
        } else {
            return fuzzy_check(list, j, k, k + 1, fuzz);
        }
    } else if fuzz <= 0 {
        return false;
    } else if i == 0 || k == list.len()-1 {
        return true;
    } else {
        return fuzzy_check(list, j, k, k+1, fuzz-1) // cut 1st
        || fuzzy_check(list, i, k, k+1, fuzz-1); // cut 2nd
    }
}

pub fn valid_sequence(a: i16, b: i16, c: i16) -> bool{
    let ab = b-a;
    let ab_sig = ab.signum();
    let ab_mag = ab.abs();
    let bc = c-b;
    let bc_sig = bc.signum();
    let bc_mag = bc.abs();
    ab_mag > 0 && ab_mag < 4 && bc_mag > 0 && bc_mag < 4 && ab_sig != 0 && ab_sig == bc_sig
}

pub fn fuzzy_check_and_count(lists: &Vec<Vec<i16>>, fuzz: u8) -> i64 {
    lists.iter().fold(0, |acc, list| if fuzzy_check(list, 0, 1, 2, fuzz) { acc + 1 } else { acc })
}
