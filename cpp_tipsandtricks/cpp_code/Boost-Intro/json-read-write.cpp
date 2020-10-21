#include "boost/lexical_cast.hpp" 
#include <bits/stdc++.h> 
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>
using namespace boost::property_tree;
using boost::lexical_cast; 
using boost::bad_lexical_cast; 

int main()
{
    ptree pt;
    pt.put("C:.Windows.System", "20 files");
    pt.put("C:.Windows.Cursors", "50 files");
    json_parser::write_json("file.json", pt);
    
    ptree pt2;
    json_parser::read_json("file.json", pt2);
    std::cout << std::boolalpha << (pt == pt2) << '\n';

    //ptree::const_iterator it = pt.find("System");
    //std::string pi = boost::lexical_cast<std::string>(it->second.get_value());
}