#include "BString.hpp"
//==============================================================================
BString::BString()
{

}
//==============================================================================
BString::BString(char* text)
  : mData(text)
{

}
//==============================================================================
BString::BString(const char* text)
  : mData(text)
{

}
//==============================================================================
BString::BString(const std::string& text)
  : mData(text)
{

}
//==============================================================================
BString::BString(const BString& text)
  : mData(text.getData())
{

}
//==============================================================================
BString::~BString()
{

}
//==============================================================================
const std::string& BString::getData() const
{
  return mData;
}
//==============================================================================
void BString::append(const BString& text)
{
  mData.append(text.getData());
}
//==============================================================================
const BString BString::operator=(const BString& text)
{
  mData = text.getData();
  return *this;
}
//==============================================================================
bool BString::operator==(const BString& text) const
{
  return mData == text.getData();
}
//==============================================================================
