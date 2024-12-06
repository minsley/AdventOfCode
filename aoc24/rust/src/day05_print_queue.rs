pub struct PrintQueueInput {
    rules: Vec<Rule>,
    updates: Vec<Update>
}

pub struct Rule {
    first: u8,
    second: u8,
}

pub struct Update(Vec<u8>);

pub fn parse(input: &str) -> PrintQueueInput {
    let mut rules: Vec<Rule> = Vec::new();
    let mut updates: Vec<Update> = Vec::new();

    let mut first_section: bool = true;
    for line in input.lines() {
        if first_section {
            if line.is_empty() { 
                first_section = false;
                continue;
            };

            let nums = line
                .split('|')
                .collect::<Vec<_>>();
            
            rules.push(Rule{
                first: nums[0].parse().unwrap(),
                second: nums[1].parse().unwrap()
            });
        } else {
            updates.push(Update(line
                .split(',')
                .map(|x| x.parse::<u8>().unwrap())
                .collect::<Vec<_>>()));
        }
    }

    PrintQueueInput{rules, updates}
}