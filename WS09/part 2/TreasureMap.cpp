// Workshop 9 - Multi-threading
//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>

// For part 2
#include <functional>
#include <future>
#include <vector>
#include <thread>

#include "TreasureMap.h"

namespace seneca{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
            std::ofstream fout(filename, std::ios::out | std::ios::binary);
            if (fout){
                // Write out the # of rows then the colSize to the file
                // then write each of the rows of the map to the file
                fout.write(reinterpret_cast<char*>(&rows), sizeof(rows));
                fout.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));
                for (size_t i = 0; i < rows; ++i){
                    fout.write(map[i].c_str(), colSize);
                }
                fout.close();
            }
            else
                throw std::string("Output file could not be opened!");
            // END TODO
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.

        std::ifstream fin(filename, std::ios::in | std::ios::binary);
        if (fin){

            if (map) // Dealloc old map if it exists
                delete [] map;

            // Read first 4 bytes for the rows then second 4 bytes for the colSize
            fin.read(reinterpret_cast<char*>(&rows), sizeof(rows));
            fin.read(reinterpret_cast<char*>(&colSize), sizeof(colSize));

            // Allocate memory for the map
            map = new std::string[rows];

            for (size_t i = 0; i < rows; ++i){
                map[i].resize((colSize)); // Resize each string before reading in
                fin.read(reinterpret_cast<char*>(&(map[i][0])), colSize);
            }

        }
        else 
           throw std::string(filename) + " could not be opened for binary reading!"; 
        // END TODO
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        //for (size_t i = 0; i < rows; ++i){
        //    count += digForTreasure(map[i], mark);
        //}

        // Part 2
        std::string data[4];
        size_t numthreads = 4;

        // Partition the data
        for (size_t i = 0; i < rows; ++i){
            size_t check = i % numthreads;
            data[check] += map[i];
        }

        // Bind and set up packaged tasks for futures/threads
        auto func = std::bind(digForTreasure, std::placeholders::_1, mark);
        std::packaged_task<size_t(const std::string&)> pt1(func);
        std::packaged_task<size_t(const std::string&)> pt2(func);
        std::packaged_task<size_t(const std::string&)> pt3(func);
        std::packaged_task<size_t(const std::string&)> pt4(func);

        std::vector<std::future<size_t>> fvec;
        fvec.push_back(pt1.get_future());
        fvec.push_back(pt2.get_future());
        fvec.push_back(pt3.get_future());
        fvec.push_back(pt4.get_future());

        std::vector<std::thread> tvec;
        tvec.push_back(std::thread(std::move(pt1), std::cref(data[0])));
        tvec.push_back(std::thread(std::move(pt2), std::cref(data[1])));
        tvec.push_back(std::thread(std::move(pt3), std::cref(data[2])));
        tvec.push_back(std::thread(std::move(pt4), std::cref(data[3])));

        for (size_t i = 0; i < numthreads; ++i)
            tvec[i].join();

        for (auto& x : fvec)
            count += x.get();

        return count;
    }
}