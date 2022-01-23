
#include "Factories/WorkerFactory.h"
#include "ConfigurationFileParser.h"





int main(int argc, char** argv) {

    const int FIRST_ARGUMENT = 1;


    lab2::ConfigurationFileParser parser((std::string(argv[FIRST_ARGUMENT])));

    parser.parse();

    lab2::WorkFlow workflow(parser.Getmap_for_blocks(), parser.Getchain_of_nodes());

    workflow.computing_pipeline();

    return 0;
}
