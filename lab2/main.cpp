#include <iostream>
#include "Factories/WorkerFactory.h"
#include "Factories/FileReaderFactory.h"


#include "ConfigurationFileParser.h"





int main() {
    lab2::ConfigurationFileParser parser("workflow.txt");

    parser.parse();

    lab2::WorkFlow workflow(parser.Getmap_for_blocks(), parser.Getchain_of_nodes());

    //workflow.print_parsed_chain();
    //workflow.print_parsed_map();


    workflow.computing_pipeline();

    return 0;
}
