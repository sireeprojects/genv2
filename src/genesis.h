#ifndef __GENESIS__
#define __GENESIS__


#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "msg.h"
using namespace std;


enum generate_type {
    fixed,
    rnd,
    pattern
};


struct genesis_txn_storage_element {
    uint32_t id;
    uint32_t offset;
    uint32_t size;
    generate_type type;
    uint32_t pattern_id;
    string print_name;
};


struct genprof_stream_control {
    uint32_t num_frames;
    uint32_t ipg;
};


struct genprof_stream_payload {
    uint32_t offset;
    uint32_t ipg;
    generate_type type;
    uint32_t pattern_id;
};


struct genprof_stream_field {
    uint32_t offset;
    uint32_t sie;
    uint32_t field_type;
    uint32_t pattern_id;
    generate_type type;
};


struct genprof_stream_udf {
    uint32_t offset;
    uint32_t size;
    uint32_t field_type;
    uint32_t pattern_id;
    generate_type type;
};


enum field_id {
    preamble    = 0,
    destination = 1,
    source      = 2,
    length      = 3,
    type        = 4,
    max_fields  = 5
};


class genesis_txn {
public:

    // ctor
    genesis_txn();

    // set fixed value
    void set(field_id id, uint64_t value);

    // get fixed value
    uint64_t get(field_id);

private: // internal storage

    vector<genesis_txn_storage_element> mem;

    // accessors
    void add_mem_item(genesis_txn_storage_element);
    genesis_txn_storage_element get_mem_item();

    void print_mem();

private: // unit tests
    void test_mem();
};


void genesis_txn::print_mem() {
    ostringstream msg;
    msg.str("");
    msg << "-----------------------------------------------------------------------------------------" << endl;
    msg << setw(15) << left << "FieldID"
        << setw(15) << left << "Offset"
        << setw(15) << left << "Size"
        << setw(15) << left << "ValType"
        << setw(15) << left << "ValStruct"
        << setw(15) << left << "Name"
        << endl;
    msg << "-----------------------------------------------------------------------------------------" << endl;
    cout << msg.str().c_str();

}


void genesis_txn::set(field_id id, uint64_t value) {

}


uint64_t genesis_txn::get(field_id id) {
    return 0;
}


genesis_txn::genesis_txn() {
    print_mem();
}


void genesis_txn::test_mem() {
}


#endif
