/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** NetX Secure Component                                                 */
/**                                                                       */
/**    Datagram Transport Layer Security (DTLS)                           */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define NX_SECURE_SOURCE_CODE


/* Include necessary system files.  */

#include "nx_secure_dtls.h"

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nxe_secure_dtls_server_protocol_version_override   PORTABLE C      */
/*                                                           6.0          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Timothy Stapko, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function checks for errors in DTLS server protocol version     */
/*    override call.                                                      */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    dtls_server                           Pointer to DTLS server        */
/*    protocol_version                      Version of DTLS to use        */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                Completion status             */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _nx_secure_dtls_server_protocol_version_override                    */
/*                                          Override DTLS protocol version*/
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     Timothy Stapko           Initial Version 6.0           */
/*                                                                        */
/**************************************************************************/
UINT _nxe_secure_dtls_server_protocol_version_override(NX_SECURE_DTLS_SERVER *dtls_server,
                                                       USHORT protocol_version)
{
#ifdef NX_SECURE_ENABLE_DTLS
UINT status;

    /* Check pointers. */
    if(dtls_server == NX_NULL)
    {
        return(NX_PTR_ERROR);
    }

    /* Make sure the version supplied is known and supported. */
    switch (protocol_version)
    {
    /* Supported DTLS versions. */
    case NX_SECURE_DTLS_VERSION_1_0:
    case NX_SECURE_DTLS_VERSION_1_2:
        break;
    default:
        return(NX_PTR_ERROR);
    }

    status = _nx_secure_dtls_server_protocol_version_override(dtls_server, protocol_version);

    /* Return completion status.  */
    return(status);
#else
    NX_PARAMETER_NOT_USED(dtls_server);
    NX_PARAMETER_NOT_USED(protocol_version);

    return(NX_NOT_SUPPORTED);
#endif
}

