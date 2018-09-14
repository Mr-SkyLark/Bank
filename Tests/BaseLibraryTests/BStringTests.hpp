#include <gtest/gtest.h>
#include <BString.hpp>

TEST(BStringTest, constructor)
{
  std::string stdString1("text1");
  std::string stdString2("text2");

  BString strEmpty;
  BString str11("text1");
  BString str12("text1");
  BString str13("text2");
  BString str21(stdString1);
  BString str22(stdString1);
  BString str23(stdString2);

  ASSERT_TRUE(str11 == str12);
  ASSERT_TRUE(str21 == str22);
  ASSERT_TRUE(str11 == str21);

  ASSERT_FALSE(str11 == str13);
  ASSERT_FALSE(str21 == str23);
  ASSERT_FALSE(str11 == str23);
  ASSERT_FALSE(str11 == strEmpty);
}
