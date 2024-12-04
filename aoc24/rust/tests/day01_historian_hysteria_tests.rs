use lib::{utils, day01_historian_hysteria};

const DIR: &str = "../info/01_historian_hysteria/input/";
const EXAMPLE_FILE: &str = "HistorianHysteriaExample.txt";
const INPUT_FILE_MINSLEY: &str = "HistorianHysteriaInput_minsley.txt";
const INPUT_FILE_MINSFB: &str = "HistorianHysteriaInput_minsfb.txt";

#[test]
fn example_1() {
    let path = [DIR, EXAMPLE_FILE].join("");
    let file = utils::read_file(path.as_str());

    let (left, right) = day01_historian_hysteria::parse(&file);
    let result = day01_historian_hysteria::sort_diff_sum(left, right);

    assert_eq!(result, 11);
}

#[test]
fn part_1_minsley() {
    let path = [DIR, INPUT_FILE_MINSLEY].join("");
    let file = utils::read_file(path.as_str());

    let (left, right) = day01_historian_hysteria::parse(&file);
    let result = day01_historian_hysteria::sort_diff_sum(left, right);

    assert_eq!(result, 1579939);
}

#[test]
fn part_1_minsfb() {
    let path = [DIR, INPUT_FILE_MINSFB].join("");
    let file = utils::read_file(path.as_str());

    let (left, right) = day01_historian_hysteria::parse(&file);
    let result = day01_historian_hysteria::sort_diff_sum(left, right);

    assert_eq!(result, 2344935);
}

#[test]
fn example_2() {
    let path = [DIR, EXAMPLE_FILE].join("");
    let file = utils::read_file(path.as_str());

    let (left, right) = day01_historian_hysteria::parse(&file);
    let result = day01_historian_hysteria::similarity(left, right);

    assert_eq!(result, 31);
}

#[test]
fn part_2_minsley() {
    let path = [DIR, INPUT_FILE_MINSLEY].join("");
    let file = utils::read_file(path.as_str());

    let (left, right) = day01_historian_hysteria::parse(&file);
    let result = day01_historian_hysteria::similarity(left, right);

    assert_eq!(result, 20351745);
}

#[test]
fn part_2_minsfb() {
    let path = [DIR, INPUT_FILE_MINSFB].join("");
    let file = utils::read_file(path.as_str());

    let (left, right) = day01_historian_hysteria::parse(&file);
    let result = day01_historian_hysteria::similarity(left, right);

    assert_eq!(result, 27647262);
}
