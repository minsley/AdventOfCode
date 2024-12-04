#[cfg(test)]
mod tests {
    const ROOT_DIR: &str = "../info/";
    mod day1_historian_hysteria {
        use aoc24::{utils, historian_hysteria};
        use crate::tests::ROOT_DIR;

        const DAY_DIR: &str = "01_historian_hysteria/input/";
        const EXAMPLE_FILE: &str = "HistorianHysteriaExample.txt";
        const INPUT_FILE_MINSLEY: &str = "HistorianHysteriaInput_minsley.txt";
        const INPUT_FILE_MINSFB: &str = "HistorianHysteriaInput_minsfb.txt";

        #[test]
        fn example_1() {
            let path = [ROOT_DIR, DAY_DIR, EXAMPLE_FILE].join("");
            let file = utils::read_file(path.as_str());
            
            let (left, right) = historian_hysteria::parse(&file);
            let result = historian_hysteria::sort_diff_sum(left, right);
            
            assert_eq!(result, 11);
        }

        #[test]
        fn part_1_minsley() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSLEY].join("");
            let file = utils::read_file(path.as_str());

            let (left, right) = historian_hysteria::parse(&file);
            let result = historian_hysteria::sort_diff_sum(left, right);

            assert_eq!(result, 1579939);
        }

        #[test]
        fn part_1_minsfb() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSFB].join("");
            let file = utils::read_file(path.as_str());

            let (left, right) = historian_hysteria::parse(&file);
            let result = historian_hysteria::sort_diff_sum(left, right);

            assert_eq!(result, 2344935);
        }

        #[test]
        fn example_2() {
            let path = [ROOT_DIR, DAY_DIR, EXAMPLE_FILE].join("");
            let file = utils::read_file(path.as_str());

            let (left, right) = historian_hysteria::parse(&file);
            let result = historian_hysteria::similarity(left, right);
            
            assert_eq!(result, 31);
        }

        #[test]
        fn part_2_minsley() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSLEY].join("");
            let file = utils::read_file(path.as_str());

            let (left, right) = historian_hysteria::parse(&file);
            let result = historian_hysteria::similarity(left, right);

            assert_eq!(result, 20351745);
        }

        #[test]
        fn part_2_minsfb() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSFB].join("");
            let file = utils::read_file(path.as_str());

            let (left, right) = historian_hysteria::parse(&file);
            let result = historian_hysteria::similarity(left, right);

            assert_eq!(result, 27647262);
        }
    }

    mod day2_red_nosed_reports {
        use aoc24::{red_nosed_reports, utils};
        use crate::tests::ROOT_DIR;

        const DAY_DIR: &str = "02_red_nosed_reports/input/";
        const EXAMPLE_FILE: &str = "RedNosedReportsExample.txt";
        const INPUT_FILE_MINSLEY: &str = "RedNosedReportsInput_minsley.txt";
        const INPUT_FILE_MINSFB: &str = "RedNosedReportsInput_minsfb.txt";

        #[test]
        fn example_1() {
            let path = [ROOT_DIR, DAY_DIR, EXAMPLE_FILE].join("");
            let file = utils::read_file(path.as_str());

            let input = red_nosed_reports::parse(&file);
            let result = red_nosed_reports::check_and_count(&input);
            assert_eq!(result, 2);
        }

        #[test]
        fn part_1_minsley() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSLEY].join("");
            let file = utils::read_file(path.as_str());

            let input = red_nosed_reports::parse(&file);
            let result = red_nosed_reports::check_and_count(&input);
            assert_eq!(result, 242);
        }

        #[test]
        fn part_1_minsfb() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSFB].join("");
            let file = utils::read_file(path.as_str());

            let input = red_nosed_reports::parse(&file);
            let result = red_nosed_reports::check_and_count(&input);
            assert_eq!(result, 402);
        }

        #[test]
        fn example_2() {
            let path = [ROOT_DIR, DAY_DIR, EXAMPLE_FILE].join("");
            let file = utils::read_file(path.as_str());
        
            let input = red_nosed_reports::parse(&file);
            let result = red_nosed_reports::check_and_count(&input);
            assert_eq!(result, 4);
        }

        #[test]
        fn part_2_minsley() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSLEY].join("");
            let file = utils::read_file(path.as_str());

            let input = red_nosed_reports::parse(&file);
            let result = red_nosed_reports::check_and_count(&input);
            assert_eq!(result, 311);
        }

        #[test]
        fn part_2_minsfb() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSLEY].join("");
            let file = utils::read_file(path.as_str());

            let input = red_nosed_reports::parse(&file);
            let result = red_nosed_reports::check_and_count(&input);
            assert_eq!(result, 455);
        }
    }

    mod day4_ceres_search {
        use aoc24::{utils, ceres_search};
        use crate::tests::ROOT_DIR;

        const DAY_DIR: &str = "04_ceres_search/input/";
        const EXAMPLE_FILE_1_1: &str = "CeresSearchExample1_1.txt";
        const EXAMPLE_FILE_1_2: &str = "CeresSearchExample1_2.txt";
        const EXAMPLE_FILE_1_3: &str = "CeresSearchExample1_3.txt";
        const INPUT_FILE_MINSLEY: &str = "CeresSearchInput_minsley.txt";
        const INPUT_FILE_MINSFB: &str = "CeresSearchInput_minsfb.txt";
        const EXAMPLE_FILE_2_1: &str = "CeresSearchExample2_1.txt";
        const EXAMPLE_FILE_2_2: &str = "CeresSearchExample2_2.txt";

        #[test]
        fn example_1_1() {
            let path = [ROOT_DIR, DAY_DIR, EXAMPLE_FILE_1_1].join("");
            let file = utils::read_file(path.as_str());

            let result = ceres_search::xmas_count(file.as_str());

            assert_eq!(result, 4);
        }

        #[test]
        fn example_1_2() {
            let path = [ROOT_DIR, DAY_DIR, EXAMPLE_FILE_1_2].join("");
            let file = utils::read_file(path.as_str());

            let result = ceres_search::xmas_count(file.as_str());

            assert_eq!(result, 18);
        }

        #[test]
        fn example_1_3() {
            let path = [ROOT_DIR, DAY_DIR, EXAMPLE_FILE_1_3].join("");
            let file = utils::read_file(path.as_str());

            let result = ceres_search::xmas_count(file.as_str());

            assert_eq!(result, 18);
        }

        #[test]
        fn part1_minsley() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSLEY].join("");
            let file = utils::read_file(path.as_str());

            let result = ceres_search::xmas_count(file.as_str());

            assert_eq!(result, 2344);
        }

        #[test]
        fn part1_minsfb() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSFB].join("");
            let file = utils::read_file(path.as_str());
        
            let result = ceres_search::xmas_count(file.as_str());
        
            assert_eq!(result, -1);
        }

        #[test]
        fn example_2_1() {
            let path = [ROOT_DIR, DAY_DIR, EXAMPLE_FILE_2_1].join("");
            let file = utils::read_file(path.as_str());

            let result = ceres_search::x_mas_count(file.as_str());

            assert_eq!(result, 1);
        }

        #[test]
        fn example_2_2() {
            let path = [ROOT_DIR, DAY_DIR, EXAMPLE_FILE_2_2].join("");
            let file = utils::read_file(path.as_str());

            let result = ceres_search::x_mas_count(file.as_str());

            assert_eq!(result, 9);
        }

        #[test]
        fn part2_minsley() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSLEY].join("");
            let file = utils::read_file(path.as_str());

            let result = ceres_search::x_mas_count(file.as_str());

            assert_eq!(result, 1815);
        }

        #[test]
        fn part2_minsfb() {
            let path = [ROOT_DIR, DAY_DIR, INPUT_FILE_MINSFB].join("");
            let file = utils::read_file(path.as_str());

            let result = ceres_search::x_mas_count(file.as_str());

            assert_eq!(result, -1);
        }
    }
}