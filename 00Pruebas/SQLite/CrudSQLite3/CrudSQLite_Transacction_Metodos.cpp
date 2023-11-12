#include <sqlite3.h>
#include <iostream>

using namespace std;

void AbrirConexion();
void Insert();
void Update();
void GetAll();
void Delete();

sqlite3* db;
sqlite3_stmt* stmt;
char* err_msg = nullptr;
int rc;

int main0() {

    system("cls");




    system("pause");
    return 0;
}

void AbrirConexion()
{
    // Abre la base de datos (crear� un nuevo archivo "example.db" si no existe)
    rc = sqlite3_open("example.db", &db);

    if (rc != SQLITE_OK) {
        cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << endl;
        return;
    }
}

void Insert()
{
    AbrirConexion();

    // Comienza una transacci�n
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, &err_msg);

    if (rc != SQLITE_OK) {
        cerr << "Error al comenzar la transacci�n: " << err_msg << endl;
        sqlite3_free(err_msg);
        return;
    }

    // Inserta datos de ejemplo
    const char* insert_data_sql = "INSERT INTO Usuarios (nombre, edad) VALUES (?, ?);";
    rc = sqlite3_prepare_v2(db, insert_data_sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        cerr << "Error al preparar la sentencia de inserci�n: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Vincula valores a la sentencia de inserci�n
    const char* nombre_insert = "John Doe";
    int edad_insert = 25;

    sqlite3_bind_text(stmt, 1, nombre_insert, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, edad_insert);

    // Ejecuta la sentencia preparada
    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        cerr << "Error al ejecutar la sentencia de inserci�n: " << sqlite3_errmsg(db) << endl;
        sqlite3_exec(db, "ROLLBACK", nullptr, nullptr, &err_msg);  // Rollback en caso de error
    }

    // Finaliza la sentencia de inserci�n
    sqlite3_finalize(stmt);

    // Cierra la base de datos
    sqlite3_close(db);
}
void Update()
{
    AbrirConexion();

    // Actualiza datos de ejemplo
    const char* update_data_sql = "UPDATE Usuarios SET edad = ? WHERE nombre = ?;";
    rc = sqlite3_prepare_v2(db, update_data_sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        cerr << "Error al preparar la sentencia de actualizaci�n: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Vincula valores a la sentencia de actualizaci�n
    int nueva_edad_update = 30;
    const char* nombre_a_actualizar = "John Doe";

    sqlite3_bind_int(stmt, 1, nueva_edad_update);
    sqlite3_bind_text(stmt, 2, nombre_a_actualizar, -1, SQLITE_STATIC);

    // Ejecuta la sentencia preparada
    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        cerr << "Error al ejecutar la sentencia de actualizaci�n: " << sqlite3_errmsg(db) << endl;
        sqlite3_exec(db, "ROLLBACK", nullptr, nullptr, &err_msg);  // Rollback en caso de error
    }

    // Finaliza la sentencia de actualizaci�n
    sqlite3_finalize(stmt);

    // Cierra la base de datos
    sqlite3_close(db);

}
void GetAll()
{
    AbrirConexion();

    // Consulta datos despu�s de las operaciones
    const char* select_data_sql = "SELECT * FROM Usuarios;";
    rc = sqlite3_prepare_v2(db, select_data_sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        cerr << "Error al preparar la sentencia de consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Ejecuta la sentencia preparada
    cout << "Datos despu�s de las operaciones:" << endl;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        cout << "ID: " << sqlite3_column_int(stmt, 0) << ", Nombre: " << sqlite3_column_text(stmt, 1) << ", Edad: " << sqlite3_column_int(stmt, 2) << endl;
    }

    if (rc != SQLITE_DONE) {
        cerr << "Error al ejecutar la sentencia de consulta: " << sqlite3_errmsg(db) << endl;
    }

    // Finaliza la sentencia de consulta
    sqlite3_finalize(stmt);

    // Cierra la base de datos
    sqlite3_close(db);

}
void Delete()
{
    AbrirConexion();

    // Elimina datos de ejemplo
    const char* delete_data_sql = "DELETE FROM Usuarios WHERE nombre = ?;";
    rc = sqlite3_prepare_v2(db, delete_data_sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        cerr << "Error al preparar la sentencia de eliminaci�n: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // Vincula valores a la sentencia de eliminaci�n
    const char* nombre_a_eliminar = "John Doe";

    sqlite3_bind_text(stmt, 1, nombre_a_eliminar, -1, SQLITE_STATIC);

    // Ejecuta la sentencia preparada
    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE) {
        cerr << "Error al ejecutar la sentencia de eliminaci�n: " << sqlite3_errmsg(db) << endl;
        sqlite3_exec(db, "ROLLBACK", nullptr, nullptr, &err_msg);  // Rollback en caso de error
    }

    // Finaliza la sentencia de eliminaci�n
    sqlite3_finalize(stmt);

    // Confirma la transacci�n
    rc = sqlite3_exec(db, "COMMIT", nullptr, nullptr, &err_msg);

    if (rc != SQLITE_OK) {
        cerr << "Error al confirmar la transacci�n: " << err_msg << endl;
        sqlite3_free(err_msg);
    }

    // Cierra la base de datos
    sqlite3_close(db);
}
