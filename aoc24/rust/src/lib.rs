pub mod day01_historian_hysteria;
pub mod day02_red_nosed_reports;
pub mod day04_ceres_search;

pub mod utils {
    pub fn read_file(filename: &str) -> String {
        std::fs::read_to_string(filename).unwrap_or_default()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn read_example_input() {
        let contents = utils::read_file("../info/01_historian_hysteria/input/HistorianHysteriaExample.txt");
        assert_eq!(contents.len(), 35);
    }
}