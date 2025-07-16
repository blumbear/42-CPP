#include "Serializer.hpp"


int main() {
	Data data;
	data._value = 42;
	data._name = "Sérialisation Test";

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized: " << raw << std::endl;

	Data *deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data -> Value: " << deserializedData->_value
				<< ", Name: " << deserializedData->_name << std::endl;

	if (deserializedData == &data) {
		std::cout << "Les objets sont identiques !" << std::endl;
	} else {
		std::cout << "Erreur : Les objets ne sont pas identiques." << std::endl;
	}
	return 0;
}