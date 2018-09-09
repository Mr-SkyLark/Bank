#include <string>

class BString
{
public:
  BString();
  BString(char* text);
  BString(const std::string& text);
  BString(const BString& text);
  ~BString();
private:
  std::string mData;
};
