#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>


const std::string rgb_path = "../rgbd_dataset_freiburg1_desk/";
const std::string rgb_txt = rgb_path + "rgb.txt";
const std::string rgb_outpath = rgb_path + "rgb_output/";


void rgbd_dataset_fr1_desk(std::string outpath) {
    std::ifstream infile;
    std::string line;

    infile.open(rgb_txt);
    if(!infile.is_open()) {
        std::cerr << rgb_txt << " error!" << std::endl;
        return;
    }

    // 读取前三行
    for (int i = 0; i < 3; i++) {
        getline(infile, line);
        std::cout << line << std::endl;
    }
    
    // 读取rgb数据
    int cnt = 1;
    std::string time_stamp;
    std::string time_stamp_file;
    while(getline(infile, line)) {
        std::stringstream stream(line);
        stream >> time_stamp >> time_stamp_file;
        std::string oldname = rgb_path + time_stamp_file;

        int result;
        std::string newname;
        std::stringstream name_stream;
        name_stream << rgb_outpath << std::setw(4) << std::setfill('0') << cnt << ".png";
        name_stream >> newname;
        std::cout << newname << std::endl;
        result = rename(oldname.c_str() , newname.c_str());
        if ( result == 0 )
            puts ( "File successfully renamed" );
        else
            perror( "Error renaming file ");
        cnt++;
    }
}


int main (int argc, char** argv) {
    rgbd_dataset_fr1_desk(rgb_outpath);
}