#include "user.h"

namespace bot::types {


User::User() : BaseObject() {}

User::User(Value const& value) : BaseObject() {
    fillObject(value);
}

User::User(string& json) : BaseObject() {
    fromString(json);
}

User::User(const User &user) : BaseObject(user) {
    is_bot = user.is_bot;
    first_name = user.first_name;
}

User::User(
    string first_name,
    bool is_bot,
    std::optional<string> last_name,
    std::optional<string> username,
    std::optional<string> language_code,
    std::optional<bool> can_join_groups,
    std::optional<bool> can_read_all_group_messages,
    std::optional<bool> supports_inline_queries
) : BaseObject(), 
    first_name(first_name),
    is_bot(is_bot),
    last_name(last_name),
    username(username),
    language_code(language_code),
    can_join_groups(can_join_groups),
    can_read_all_group_messages(can_read_all_group_messages),
    supports_inline_queries(supports_inline_queries)
{}

User::~User() {}

void User::fromNestedObject(const Value &value) {
    Parent::fromNestedObject(value);
    is_bot = value[IS_BOT.c_str()].GetBool();
    first_name = value[FIRST_NAME.c_str()].GetString();
    last_name = getOptString(value, LAST_NAME);
    username = getOptString(value, USERNAME);
    language_code = getOptString(value, LANGUAGE_CODE);
    can_join_groups = getOptBool(value, CAN_JOIN_GROUPS);
    can_read_all_group_messages = getOptBool(value, CAN_READ_ALL_GROUP_MESSAGES);
    supports_inline_queries = getOptBool(value, SUPPORT_INLINE_QUERIES);
}

void User::fillObject(rapidjson::Value const &document) {
    Parent::fillObject(document);
    is_bot = document[IS_BOT.c_str()].GetBool();
    first_name = document[FIRST_NAME.c_str()].GetString();
    last_name = getOptString(document, LAST_NAME);
    username = getOptString(document, USERNAME);
    language_code = getOptString(document, LANGUAGE_CODE);
    can_join_groups = getOptBool(document, CAN_JOIN_GROUPS);
    can_read_all_group_messages = getOptBool(document, CAN_READ_ALL_GROUP_MESSAGES);
    supports_inline_queries = getOptBool(document, SUPPORT_INLINE_QUERIES);
}

void User::fillDocument(Writer &writer) const {
    Parent::fillDocument(writer);
    writer.Key(IS_BOT.c_str());
    writer.Bool(is_bot);

    writer.Key(FIRST_NAME.c_str());
    writer.String(first_name.c_str());

    if(last_name){
        writer.Key(LAST_NAME.c_str());
        writer.String(last_name->c_str());
    }
    if(username) {
        writer.Key(USERNAME.c_str());
        writer.String(username->c_str());
    }
    if(language_code) {
        writer.Key(LANGUAGE_CODE.c_str());
        writer.String(language_code->c_str());
    }
    if(can_join_groups) {
        writer.Key(CAN_JOIN_GROUPS.c_str());
        writer.Bool(*can_join_groups);
    }

    if(supports_inline_queries){
        writer.Key(SUPPORT_INLINE_QUERIES.c_str());
        writer.Bool(*supports_inline_queries);
    }
}


size_t User::hash() const {
    std::vector<size_t> hash_vect;
    hash_vect.push_back(BaseObject::hash());
    hash_vect.push_back(std::hash<bool>{}(is_bot));
    hash_vect.push_back(std::hash<std::string>{}(first_name));

    if(last_name)
        hash_vect.push_back(std::hash<std::string>{}(*last_name));

    if(username)
        hash_vect.push_back(std::hash<std::string>{}(*username));

    if(language_code)
        hash_vect.push_back(std::hash<std::string>{}(*language_code));
    
    if(can_join_groups)
        hash_vect.push_back(std::hash<bool>{}(*can_join_groups));

    if(can_read_all_group_messages)
        hash_vect.push_back(std::hash<bool>{}(*can_read_all_group_messages));

    if(supports_inline_queries)
        hash_vect.push_back(std::hash<bool>{}(*supports_inline_queries));

    return BaseObject::combineHash(hash_vect);
}


}
