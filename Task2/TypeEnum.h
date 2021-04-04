#pragma once
#include <string>
enum AccessModifier {
    PUBLIC,
    PRIVATE,
    PROTECTED,
    NO_MODIF

};

enum ClassType {

    ABSTRACT,
    INTERFACE,
    NO_TYPE
};

inline const std::string AccessModifierToString(AccessModifier am) {
    
    switch (am) {

        case PUBLIC:
            return "public";
        case PRIVATE:
            return "private";
        case PROTECTED:
            return "protected";
        default:
            return "";
    }
}

inline const std::string ClassTypeToString(ClassType ct) {

    switch (ct) {

    case ABSTRACT:
        return "abstract class";
    case INTERFACE:
        return "interface";
    default:
        return "class";
    }
}
