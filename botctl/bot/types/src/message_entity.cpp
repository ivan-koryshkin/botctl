#include "message_entity.h"


namespace bot::types
{

MessageEntity::MessageEntity(const Value& value) {
    fillObject(value);
}

MessageEntity::MessageEntity(string &json) {
    fromString(json);
}

MessageEntity::MessageEntity(
    string type, 
    int offset, 
    int length,
    std::optional<string> url,
    std::optional<User> user,
    std::optional<string> language
):  
    BaseObject(), 
    type(type), 
    offset(offset), 
    length(length), 
    url(url), 
    user(user), 
    language(language)
{

}

MessageEntity::~MessageEntity() {

}

void MessageEntity::fillDocument(Writer &writer) const {
    writer.Key(TYPE.c_str());
    writer.String(type.c_str());

    writer.Key(OFFSET.c_str());
    writer.Int(offset);

    writer.Key(LENGTH.c_str());
    writer.Int(length);

    if(url) {
        writer.Key(URL.c_str());
        writer.String(url->c_str());
    }

    if(user) {
        writer.Key(USER.c_str());
        user->asNestedObject(writer);
    }

    if(language) {
        writer.Key(LANGUAGE.c_str());
        writer.String(language->c_str());
    }
}

void MessageEntity::fillObject(rapidjson::Value const& document) {
    type = document[TYPE.c_str()].GetString();
    offset = document[OFFSET.c_str()].GetInt();
    length = document[LENGTH.c_str()].GetInt();

    if(document.HasMember(URL.c_str()))
        url = document[URL.c_str()].GetString();

    if(document.HasMember(USER.c_str()))
    {
        const Value& nested_object = document[USER.c_str()];
        user.emplace(User(nested_object));
    }

    if(document.HasMember(LANGUAGE.c_str()))
        language = document[LANGUAGE.c_str()].GetString();
}


}
