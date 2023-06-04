// Authour: Sekacorn

#ifndef ORACLE_DATABASE_CONNECTION_H
#define ORACLE_DATABASE_CONNECTION_H

#include <oci.h> // OCI headers

class OracleDatabaseConnection {
private:
    void CheckError(OCIError* err, sword status);

public:
    void ConnectToDatabase();
};

#endif  // ORACLE_DATABASE_CONNECTION_H


