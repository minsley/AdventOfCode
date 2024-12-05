use lib::{day02_red_nosed_reports, utils};

const DIR: &str = "../info/02_red_nosed_reports/input/";
const EXAMPLE_FILE: &str = "RedNosedReportsExample.txt";
const INPUT_FILE_MINSLEY: &str = "RedNosedReportsInput_minsley.txt";
const INPUT_FILE_MINSFB: &str = "RedNosedReportsInput_minsfb.txt";

#[test]
fn example_1() {
    let path = [DIR, EXAMPLE_FILE].join("");
    let file = utils::read_file(path.as_str());

    let input = day02_red_nosed_reports::parse(&file);
    let result = day02_red_nosed_reports::check_and_count(&input);
    assert_eq!(result, 2);
}

#[test]
fn part_1_minsley() {
    let path = [DIR, INPUT_FILE_MINSLEY].join("");
    let file = utils::read_file(path.as_str());

    let input = day02_red_nosed_reports::parse(&file);
    let result = day02_red_nosed_reports::check_and_count(&input);
    assert_eq!(result, 242);
}

#[test]
fn part_1_minsfb() {
    let path = [DIR, INPUT_FILE_MINSFB].join("");
    let file = utils::read_file(path.as_str());

    let input = day02_red_nosed_reports::parse(&file);
    let result = day02_red_nosed_reports::check_and_count(&input);
    assert_eq!(result, 402);
}

#[test]
fn example_2() {
    let path = [DIR, EXAMPLE_FILE].join("");
    let file = utils::read_file(path.as_str());

    let input = day02_red_nosed_reports::parse(&file);
    let result = day02_red_nosed_reports::check_with_errors_and_count(input, 1);
    assert_eq!(result, 4);
}

#[test]
fn extra_2() {
}

#[test]
fn part_2_minsley() {
    let path = [DIR, INPUT_FILE_MINSLEY].join("");
    let file = utils::read_file(path.as_str());

    let input = day02_red_nosed_reports::parse(&file);
    let result = day02_red_nosed_reports::check_with_errors_and_count(input, 1);
    assert_eq!(result, 311);
}

#[test]
fn part_2_minsfb() {
    let path = [DIR, INPUT_FILE_MINSLEY].join("");
    let file = utils::read_file(path.as_str());

    let input = day02_red_nosed_reports::parse(&file);
    let result = day02_red_nosed_reports::check_with_errors_and_count(input, 1);
    assert_eq!(result, 455);
}