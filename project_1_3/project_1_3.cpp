#include <iostream>
#include <vector>

std::vector<double> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<double> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    //std::cout << "prev_location: " << prev_location << std::endl;
    //std::cout << "next_location: " << next_location << std::endl;
    // substr [,]
    //std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
    result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  return result;
}

int main() {
  std::vector<double> x;
  std::vector<double> w;
  std::vector<double> y;
  bool pack_with_zeros = true;

  std::string s;
  std::cin >> s;
  if(s == "false") {
    pack_with_zeros = false;
  }
  std::cin >> s;
  x = readInVector(s);
  std::cin >> s;
  w = readInVector(s);

  // TODO write your code here
  // =========== START =========

  std::cout << "x: {";

  for (int i = 0; i < x.size() - 1; i++)
  {
  	std::cout << x[i] << ", ";
  }

  std::cout << x[x.size()-1] << "}" << std::endl;

  std::cout << "w: {";

  for (int i = 0; i < w.size() - 1; i++)
  {
  	std::cout << w[i] << ", ";
  }

  std::cout << w[w.size()-1] << "}" << std::endl;

  for (int i = 0; i < x.size(); i++) 
  {

  	int conSum = 0;

  	for (int j = 0; j < w.size(); j++) {

  		int index = i + j - (w.size()/2);

  		if (!pack_with_zeros && index < 0)
  		{
  			conSum += x[0] * w[j];
  		}
  		else if (!pack_with_zeros && index >= x.size())
  		{
  			conSum += x[x.size()-1] * w[j];
  		}
  		else {
  			conSum += x[index] * w[j];
  		}

  	}

  	y.push_back(conSum);

  }

  //output

  std::cout << "{";

  for (int i = 0; i < y.size() - 1; i++)
  {
  	std::cout << y[i] << ", ";
  }

  std::cout << y[y.size()-1] << "}" << std::endl;


  // =========== END ===========
}

