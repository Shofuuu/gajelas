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
    int spc_idx = 0; // space index
    int spc_pos[255]; //

    // convert to upper case
    cargv = argv[1];
    for(unsigned long i=0; i<cargv.length(); i++)
      result += convert_toupr(cargv[i]);

    // check where is space position
    for(unsigned long i=0; i<result.length(); i++){
      if((int)result[i] == 32){
        spc_pos[spc_idx] = i;
        spc_idx++;
      }
    }

    // remove the space
    cargv = result;
    result = "";
    for(unsigned long i=0; i<cargv.length(); i++){
      if(cargv[i] != (char)32)
        result += cargv[i];
    }

    // convert the text
    result = odd_convert(result);

    // Bring back the space to the text
    cargv = result;
    result = "";
    spc_idx = 0; // reset the index value
    int error = 0;

    for(unsigned long i=0; i<cargv.length(); i++){
      if(i == (unsigned long)(spc_pos[spc_idx] - error)){
        result += (char)32;
        result += cargv[i];

        if(spc_idx >= 0)
          error++;
        spc_idx++;
      }else result += cargv[i];
    }
    std::cout << std::endl;

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
