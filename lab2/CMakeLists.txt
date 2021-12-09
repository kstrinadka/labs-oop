cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp ConfigurationFileParser.cpp ConfigurationFileParser.h WorkFlow.cpp WorkFlow.h
         Workers/Worker.cpp Workers/Worker.h Workers/WorkerReadFile.cpp Workers/WorkerReadFile.h Factories/WorkerFactory.cpp Factories/WorkerFactory.h Factories/FileReaderFactory.cpp Factories/FileReaderFactory.h Workers/WorkerWriteFile.cpp Workers/WorkerWriteFile.h Factories/FileWriterFactory.cpp Factories/FileWriterFactory.h Workers/WorkerGrep.cpp Workers/WorkerGrep.h Factories/GrepFactory.cpp Factories/GrepFactory.h Workers/WorkerSort.cpp Workers/WorkerSort.h Factories/SortFactory.cpp Factories/SortFactory.h Workers/WorkerReplace.cpp Workers/WorkerReplace.h Factories/ReplaceFactory.cpp Factories/ReplaceFactory.h Workers/WorkerDump.cpp Workers/WorkerDump.h Factories/DumpFactory.cpp Factories/DumpFactory.h Exceptions/CompileTimeException.h Exceptions/RuntimeExceptions.h Exceptions/ParseExceptions.h)
