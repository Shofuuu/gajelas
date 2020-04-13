#include <iostream>

std::string odd_convert(std::string str);
char convert_tolwr(char c);
char convert_toupr(char c);

int main(int argc, char* argv[]){
  if( ((argc < 2) | (argc > 2)) )
    std::cout << "KeKuRaNgAn/KeLeBihAn ArGuMeN!" << std::endl;
  else{
    std::string result = "";
    std::string cargv = "";

    cargv = argv[1];
    for(unsigned long i=0; i<cargv.length(); i++)
      result += convert_toupr(cargv[i]);
    std::cout << result << std::endl;

    result = odd_convert(result);
    std::cout << result << std::endl << std::endl;
  }

  return 0;
}

std::string odd_convert(std::string str){
  std::string tmp = "";

  for(unsigned long x=0; x<str.length(); x++){
    if(x%2 != 0){
      tmp += convert_tolwr(str[x]);
      //tmp += str[x];
    }else tmp += str[x];
  }

  return tmp;
}

char convert_tolwr(char c){
  int x = 0;

  if( (((int)c < 65) | ((int)c >= 90)) )
    return c;
  for(x=65; x<=90; x++){
    if(c == x)
      break;
  }
  return (char)((int)c+32);
}

char convert_toupr(char c){
  int x = 0;

  if( (((int)c < 97) | ((int)c >= 122)) )
    return c;
  for(x=97; x<=122; x++){
    if(c == x)
      break;
  }
  return (char)((int)c-32);
}
