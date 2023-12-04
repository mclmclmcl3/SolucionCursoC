#pragma once

#include <iostream>

class CryptoUtils {
public:
	//Función estática para encriptar
	static std::string Encrypt(const std::string& plaintext, const std::string& key) {
		std::string ciphertext = plaintext;
		for (size_t i = 0; i < plaintext.size(); ++i) {
			ciphertext[i] ^= key[i % key.size()];
		}
		return ciphertext;
	}

	// Función estática para desencriptar (llama a Encrypt porque XOR es simétrico)
	static std::string Decrypt(const std::string& ciphertext, const std::string& key) {
		return Encrypt(ciphertext, key);
	}

	//// PARA HACER PRUEBAS HE DESACTIVADO LOS ENCRIPT, estan probados y funcionan, pero en algun caso me ha dato una cosa rara, hay que chequearlos.

	//static std::string Encrypt(const std::string& plaintext, const std::string& key) {
	//    return plaintext;
	//}

	//// Función estática para desencriptar (llama a Encrypt porque XOR es simétrico)
	//static std::string Decrypt(const std::string& ciphertext, const std::string& key) {
	//    return ciphertext;
	//}
};