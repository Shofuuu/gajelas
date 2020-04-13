#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main(int argc, char* argv[]){
	if(argc < 2){
		std::cout << "Tiling biri sitidiknyi 1 tilisin" << std::endl;
		std::cout << "cintihnyi : \n" << argv[0] << " \"terserah\"\n" << std::endl;
	}

	std::string tmp_arr[255];
	std::string tmp = "";
	std::string vowels = "aiueoAIUEO";
	std::string data = "";
	bool flag = 0;

	for(int x=1;x<argc;x++){
		tmp_arr[x] = std::string(argv[x]);
	}

	std::transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c){return std::tolower(c);});

	for(int z=1;z<argc;z++){
		tmp = tmp_arr[z];
		data = "";

		for(int x=0;x<tmp.length();x++){
			for(int y=0; y<vowels.length(); y++){
				if(tmp[x] == vowels[y]){
					data += "i";
					flag = 0;
					break;
				}else{
					flag = 1;
				}
			}

			if(flag == 1){
				data += tmp[x];
			}
		}
		std::cout << data << "\n" << std::endl;
	}

	return 0;
}
