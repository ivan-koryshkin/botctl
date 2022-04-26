#include <gtest/gtest.h>
#include "../chat_member.h"

namespace chat_member_test {

using namespace std;
using namespace bot::types;

User user("test", true);
string status = "left";
ChatMember member0(user, status);

TEST(chat_member_test, constructor_params) {
    ASSERT_EQ(member0.user, user);
    ASSERT_EQ(member0.status, status);
}

TEST(chat_member_test, serialize) {
    string json = member0.toString();
    ChatMember member1(json);
    ASSERT_EQ(member1.user, user);
    ASSERT_EQ(member1.status, status);
}

}