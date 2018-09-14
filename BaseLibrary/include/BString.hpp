#include <string>

class BString
{
public:
  BString();
  BString(char* text);
  BString(const char* text);
  BString(const std::string& text);
  BString(const BString& text);
  ~BString();

  const std::string& getData() const;

  void append(const BString& text);

  const BString operator=(const BString& str);
  bool operator==(const BString& str) const;


private:
  std::string mData;
};
