
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
