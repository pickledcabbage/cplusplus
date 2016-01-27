#include <iostream>

#include "object1.h"

void temp::int_data(int d){
  data1 = d;
  cout << "Number: " << data1;
}

float temp::float_data(){
  cout << "\nEnter data: ";
  cin >> data2;
 return data2;
}
