cmake_minimum_required(VERSION 3.28)
project(aoc24)

set(CMAKE_CXX_STANDARD 17)

add_executable(aoc24
        main.cpp
        lib/doctest.h
        util/TestHelper.h
        util/TestHelper.cpp
        01_historian_hysteria/HistorianHysteria.h
        01_historian_hysteria/HistorianHysteriaPart1.cpp
        01_historian_hysteria/HistorianHysteriaPart2.cpp
        01_historian_hysteria/test/HistorianHysteriaTest.cpp
        02_red_nosed_reports/RedNosedReports.h
        02_red_nosed_reports/RedNosedReportsPart1.cpp
        02_red_nosed_reports/RedNosedReportsPart2.cpp
        02_red_nosed_reports/test/RedNosedReportsTest.cpp
        03_mull_it_over/MullItOver.h
        03_mull_it_over/MullItOverPart1.cpp
        03_mull_it_over/MullItOverPart2.cpp
        03_mull_it_over/test/MullItOverTest.cpp
        05_print_queue/PrintQueue.h
        05_print_queue/PrintQueue.cpp
        05_print_queue/test/PrintQueueTest.cpp
        06_guard_gallivant/GuardGallivant.h
        06_guard_gallivant/GuardGallivant.cpp
        06_guard_gallivant/test/GuardGallivantTest.cpp
        07_bridge_repair/BridgeRepair.h
        07_bridge_repair/BridgeRepair.cpp
        07_bridge_repair/test/BridgeRepairTest.cpp
        08_resonant_collinearity/ResonantCollinearity.h
        08_resonant_collinearity/ResonantCollinearity.cpp
        08_resonant_collinearity/test/ResonantCollinearityTest.cpp
        09_disk_fragmenter/DiskFragmenter.h
        09_disk_fragmenter/DiskFragmenter.cpp
        09_disk_fragmenter/test/DiskFragmenterTest.cpp
        10_hoof_it/HoofIt.h
        10_hoof_it/HoofIt.cpp
        10_hoof_it/test/HoofItTest.cpp)

file(GLOB INPUT_FILES ../info/**/input/*)
file(COPY ${INPUT_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
