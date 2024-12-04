use aoc24::*;

#[cfg(test)]
mod tests {
    use aoc24::historian_hysteria::historian_hysteria;
    use super::*;

    #[test]
    fn example_1() {
        let file = utils::read_file("../info/01_historian_hysteria/input/HistorianHysteriaExample.txt");
        let (left, right) = historian_hysteria::parse(&file);
        let result = historian_hysteria::sort_diff_sum(left, right);
        assert_eq!(result, 11);
    }
    
    #[test]
    fn day01_historian_hysteria_part1() {
        let file = utils::read_file("../info/01_historian_hysteria/input/HistorianHysteriaInput_minsley.txt");
        let (left, right) = historian_hysteria::parse(&file);
        let result = historian_hysteria::sort_diff_sum(left, right);
        assert_eq!(result, 1579939);
    }
    
    #[test]
    fn example_2() {
        let file = utils::read_file("../info/01_historian_hysteria/input/HistorianHysteriaExample.txt");
        let (left, right) = historian_hysteria::parse(&file);
        let result = historian_hysteria::similarity(left, right);
        assert_eq!(result, 31);
    }
    
    #[test]
    fn day01_historian_hysteria_part2() {
        let file = utils::read_file("../info/01_historian_hysteria/input/HistorianHysteriaInput_minsley.txt");
        let (left, right) = historian_hysteria::parse(&file);
        let result = historian_hysteria::similarity(left, right);
        assert_eq!(result, 20351745);
    }
}