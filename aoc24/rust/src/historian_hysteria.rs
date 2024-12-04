use std::collections::HashMap;

pub fn dist(left: u64, right: u64) -> u64 {
    right.abs_diff(left)
}

pub fn parse(input: &str) -> (Vec<u64>, Vec<u64>) {
    let mut result: (Vec<u64>, Vec<u64>) = (Vec::new(), Vec::new());

    for line in input.lines() {
        let splits = line.split("   ").collect::<Vec<&str>>();
        let a = splits[0].parse::<u64>().unwrap();
        let b = splits[1].parse::<u64>().unwrap();
        result.0.push(a);
        result.1.push(b);
    }

    result
}

pub fn sort_diff_sum(left: Vec<u64>, right: Vec<u64>) -> u64 {
    let mut l = left.to_vec();
    let mut r = right.to_vec();
    l.sort();
    r.sort();
    std::iter::zip(l, r).fold(0, |acc, (a, b)| acc + dist(a, b))
}

pub fn similarity(left: Vec<u64>, right: Vec<u64>) -> u64 {
    let r = right.into_iter()
        .fold(HashMap::new(), |mut acc, item| {
            *acc.entry(item).or_insert(0) += 1;
            acc
        });
    left.iter().fold(0, |acc, x| { 
        acc + (x * r.get(&x).unwrap_or(&0u64)) 
    })
}

