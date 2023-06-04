// Authour: Sekacorn

#include <iostream>
#include <oci.h>
#include "OracleDatabaseConnection.h"

// Function handling OCI errors
void OracleDatabaseConnection::CheckError(OCIError* err, sword status) {
    if (status != OCI_SUCCESS) {
        text errBuf[512];
        sb4 errCode;

        // Retrieve the error information from the OCIError structure
        OCIErrorGet(err, 1, NULL, &errCode, errBuf, sizeof(errBuf), OCI_HTYPE_ERROR);

        // Print the OCI error code and error message
        std::cerr << "OCI Error " << errCode << ": " << errBuf << std::endl;

        // Exit the program if an OCI error occurs
        exit(1);
    }
}

// Function establishing the database connection
void OracleDatabaseConnection::ConnectToDatabase() {
    OCIEnv* env;
    OCIError* err;
    OCISvcCtx* svcCtx;
    OCIServer* srv;
    OCISession* usrSession;

    // Creating an OCI environment
    CheckError(OCIEnvCreate(&env, OCI_DEFAULT, NULL, NULL, NULL, NULL, 0, NULL), OCI_SUCCESS);

    // Allocating the OCI error handle
    CheckError(OCIHandleAlloc(env, (dvoid**)&err, OCI_HTYPE_ERROR, 0, NULL), OCI_SUCCESS);

    // Allocating the OCI server handle
    CheckError(OCIHandleAlloc(env, (dvoid**)&srv, OCI_HTYPE_SERVER, 0, NULL), OCI_SUCCESS);

    // Allocating the OCI service context handle
    CheckError(OCIHandleAlloc(env, (dvoid**)&svcCtx, OCI_HTYPE_SVCCTX, 0, NULL), OCI_SUCCESS);

    // Allocating the OCI user session handle
    CheckError(OCIHandleAlloc(env, (dvoid**)&usrSession, OCI_HTYPE_SESSION, 0, NULL), OCI_SUCCESS);

    // Setting the server attribute to the database name
    CheckError(OCIAttrSet(srv, OCI_HTYPE_SERVER, (dvoid*)"ORCLCDB", 8, OCI_ATTR_SERVER, err), OCI_SUCCESS);

    // Setting the server attribute in the service context handle
    CheckError(OCIAttrSet(svcCtx, OCI_HTYPE_SVCCTX, srv, 0, OCI_ATTR_SERVER, err), OCI_SUCCESS);

    // Setting the username attribute in the user session handle
    CheckError(OCIAttrSet(usrSession, OCI_HTYPE_SESSION, (dvoid*)"hr", 2, OCI_ATTR_USERNAME, err), OCI_SUCCESS);

    // Setting the password attribute in the user session handle
    CheckError(OCIAttrSet(usrSession, OCI_HTYPE_SESSION, (dvoid*)"password", 8, OCI_ATTR_PASSWORD, err), OCI_SUCCESS);

    // Beginning the user session
    CheckError(OCISessionBegin(svcCtx, err, usrSession, OCI_CRED_RDBMS, OCI_DEFAULT), OCI_SUCCESS);

    // Setting the user session attribute in the service context handle
    CheckError(OCIAttrSet(svcCtx, OCI_HTYPE_SVCCTX, usrSession, 0, OCI_ATTR_SESSION, err), OCI_SUCCESS);

    // You can choose to execute SQL queries or perform database operations here

    // Ending the user session
    CheckError(OCISessionEnd(svcCtx, err, usrSession, OCI_DEFAULT), OCI_SUCCESS);

    // Detaching the server
    CheckError(OCIServerDetach(srv, err, OCI_DEFAULT), OCI_SUCCESS);

    // Freeing the allocated handles
    OCIHandleFree(svcCtx, OCI_HTYPE_SVCCTX);
    OCIHandleFree(srv, OCI_HTYPE_SERVER);
    OCIHandleFree(usrSession, OCI_HTYPE_SESSION);
    OCIHandleFree(err, OCI_HTYPE_ERROR);
    OCIHandleFree(env, OCI_HTYPE_ENV);
}
