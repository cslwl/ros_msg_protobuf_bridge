#include <iomanip>
#include <iostream>

#include "cslwl.pb.h"

void PrintHex(const std::string& str) {
  for (const unsigned char c : str) {
    std::cout << std::hex << std::setw(2) << std::setfill('0')
              << static_cast<int>(c);
  }
  std::cout << std::endl;
}

int main() {
  
  std::string des;
  const google::protobuf::Descriptor* descriptor =
      cslwl::sample::RosProtoTest::descriptor();
  for (int i = 0; i < descriptor->field_count(); ++i) {
    const google::protobuf::FieldDescriptor* field = descriptor->field(i);

    des.append("value_name: ");
    des.append(field->name());
    des.append("; ");
    des.append("type: ");
    des.append(google::protobuf::FieldDescriptor::TypeName(field->type()));
    des.append(";\n");
  }
  std::cout << des << std::endl;
}