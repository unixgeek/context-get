#include <tinyxml2.h>

#include <iostream>

int
main(int argc, char *argv[]) {
    std::string context;
    std::string target;

    if (argc == 3) {
        context = argv[1];
        target = argv[2];
    } else {
        std::cout << "usage: " << argv[0] << " CONTEXT_FILE ENVIRONMENT_NAME" << std::endl;
        return 1;
    }

    if (context.empty()) {
        std::cerr << "No context file specified" << std::endl;
        return 1;
    }

    if (target.empty()) {
        std::cerr << "No environment name specified" << std::endl;
        return 1;
    }

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError loadStatus = doc.LoadFile(context.c_str());

    if (loadStatus != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error loading file: " << doc.ErrorStr() << std::endl;
        return 1;
    }

    tinyxml2::XMLElement *contextElement = doc.FirstChildElement("Context");
    if (contextElement == nullptr) {
        std::cerr << "Couldn't find the root Context element" << std::endl;
        return 1;
    }

    tinyxml2::XMLElement *environmentElement = contextElement->FirstChildElement("Environment");

    bool foundIt = false;

    while (!foundIt && environmentElement != nullptr) {
        std::string name;

        name = environmentElement->Attribute("name");
        if (target == name) {
            foundIt = true;
            std::cout << environmentElement->Attribute("value");
        }

        environmentElement = environmentElement->NextSiblingElement("Environment");

    }
}
