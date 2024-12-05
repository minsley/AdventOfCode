use lib::{utils, day05_print_queue};

const DIR: &str = "../info/05_print_queue/input/";
const EXAMPLE_FILE_1_1: &str = "print_queue_example.txt";
const INPUT_FILE_MINSLEY: &str = "print_queue_input1_minsley.txt";
const INPUT_FILE_MINSFB: &str = "print_queue_input1_minsfb.txt";

#[test]
fn example_1_1() {
    let path = [DIR, EXAMPLE_FILE_1_1].join("");
    let file = utils::read_file(path.as_str());

    // let result = day04_ceres_search::xmas_count(file.as_str());

    // assert_eq!(result, 4);
}

#[test]
fn part1_minsley() {
    let path = [DIR, INPUT_FILE_MINSLEY].join("");
    let file = utils::read_file(path.as_str());

    // let result = day04_ceres_search::xmas_count(file.as_str());

    // assert_eq!(result, 2344);
}

#[test]
fn part1_minsfb() {
    let path = [DIR, INPUT_FILE_MINSFB].join("");
    let file = utils::read_file(path.as_str());

    // let result = day04_ceres_search::xmas_count(file.as_str());

    // assert_eq!(result, 2427);
}