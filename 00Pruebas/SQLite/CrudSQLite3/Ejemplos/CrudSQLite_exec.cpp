//#include <sqlite3.h>
//#include <iostream>
//
//using namespace std;
//
//int callback(void* NotUsed, int argc, char** argv, char** azColName) {
//    // Esta función se llama para cada fila del resultado de la consulta
//    for (int i = 0; i < argc; i++) {
//        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
//    }
//    cout << "-------------------------" << endl;
//    return 0;
//}
//
//int main3() {
//    sqlite3* db;
//    char* err_msg = nullptr;
//
//    // Abre la base de datos (creará un nuevo archivo "example.db" si no existe)
//    int rc = sqlite3_open("example.db", &db);
//
//    if (rc != SQLITE_OK) {
//        cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << endl;
//        return rc;
//    }
//
//    // Crea una tabla si no existe
//    const char* create_table_sql = "CREATE TABLE IF NOT EXISTS Usuarios(id INTEGER PRIMARY KEY, nombre TEXT, edad INTEGER);";
//    rc = sqlite3_exec(db, create_table_sql, nullptr, nullptr, &err_msg);
//
//    if (rc != SQLITE_OK) {
//        cerr << "Error al crear la tabla: " << err_msg << endl;
//        sqlite3_free(err_msg);
//    }
//
//    // Inserta datos de ejemplo
//    const char* insert_data_sql = "INSERT INTO Usuarios (nombre, edad) VALUES ('John Doe', 25);";
//    rc = sqlite3_exec(db, insert_data_sql, nullptr, nullptr, &err_msg);
//
//    if (rc != SQLITE_OK) {
//        cerr << "Error al insertar datos: " << err_msg << endl;
//        sqlite3_free(err_msg);
//    }
//
//    // Consulta datos
//    const char* select_data_sql = "SELECT * FROM Usuarios;";
//    rc = sqlite3_exec(db, select_data_sql, callback, nullptr, &err_msg);
//
//    if (rc != SQLITE_OK) {
//        cerr << "Error al consultar datos: " << err_msg << endl;
//        sqlite3_free(err_msg);
//    }
//
//    // Cierra la base de datos
//    sqlite3_close(db);
//
//    return 0;
//}
