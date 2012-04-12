/*
 * String.h
 *
 *  Created on: Mar 31, 2012
 *      Author: yanock
 */
#include <vector>
#include <string>


#ifndef STRING_H_
#define STRING_H_

std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

#endif /* STRING_H_ */
