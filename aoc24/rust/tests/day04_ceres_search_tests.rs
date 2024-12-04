use lib::{utils, day04_ceres_search};

const DIR: &str = "../info/04_ceres_search/input/";
const EXAMPLE_FILE_1_1: &str = "CeresSearchExample1_1.txt";
const EXAMPLE_FILE_1_2: &str = "CeresSearchExample1_2.txt";
const EXAMPLE_FILE_1_3: &str = "CeresSearchExample1_3.txt";
const INPUT_FILE_MINSLEY: &str = "CeresSearchInput_minsley.txt";
const INPUT_FILE_MINSFB: &str = "CeresSearchInput_minsfb.txt";
const EXAMPLE_FILE_2_1: &str = "CeresSearchExample2_1.txt";
const EXAMPLE_FILE_2_2: &str = "CeresSearchExample2_2.txt";

#[test]
fn example_1_1() {
    let path = [DIR, EXAMPLE_FILE_1_1].join("");
    let file = utils::read_file(path.as_str());

    let result = day04_ceres_search::xmas_count(file.as_str());

    assert_eq!(result, 4);
}

#[test]
fn example_1_2() {
    let path = [DIR, EXAMPLE_FILE_1_2].join("");
    let file = utils::read_file(path.as_str());

    let result = day04_ceres_search::xmas_count(file.as_str());

    assert_eq!(result, 18);
}

#[test]
fn example_1_3() {
    let path = [DIR, EXAMPLE_FILE_1_3].join("");
    let file = utils::read_file(path.as_str());

    let result = day04_ceres_search::xmas_count(file.as_str());

    assert_eq!(result, 18);
}

#[test]
fn part1_minsley() {
    let path = [DIR, INPUT_FILE_MINSLEY].join("");
    let file = utils::read_file(path.as_str());

    let result = day04_ceres_search::xmas_count(file.as_str());

    assert_eq!(result, 2344);
}

#[test]
fn part1_minsfb() {
    let path = [DIR, INPUT_FILE_MINSFB].join("");
    let file = utils::read_file(path.as_str());

    let result = day04_ceres_search::xmas_count(file.as_str());

    assert_eq!(result, 2427);
}

#[test]
fn example_2_1() {
    let path = [DIR, EXAMPLE_FILE_2_1].join("");
    let file = utils::read_file(path.as_str());

    let result = day04_ceres_search::x_mas_count(file.as_str());

    assert_eq!(result, 1);
}

#[test]
fn example_2_2() {
    let path = [DIR, EXAMPLE_FILE_2_2].join("");
    let file = utils::read_file(path.as_str());

    let result = day04_ceres_search::x_mas_count(file.as_str());

    assert_eq!(result, 9);
}

#[test]
fn part2_minsley() {
    let path = [DIR, INPUT_FILE_MINSLEY].join("");
    let file = utils::read_file(path.as_str());

    let result = day04_ceres_search::x_mas_count(file.as_str());

    assert_eq!(result, 1815);
}

#[test]
fn part2_minsfb() {
    let path = [DIR, INPUT_FILE_MINSFB].join("");
    let file = utils::read_file(path.as_str());

    let result = day04_ceres_search::x_mas_count(file.as_str());

    assert_eq!(result, 1900);
}
