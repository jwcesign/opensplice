#ifndef IN_CONNECTIVITYENTITY_FACADE_H_
#define IN_CONNECTIVITYENTITY_FACADE_H_

/* Abstraction layer includes */
#include "os_classbase.h"

/* DDSi includes */
#include "in__object.h"
#include "in_ddsiElements.h"

#if defined (__cplusplus)
extern "C" {
#endif

/**
 * The usual cast-method for class in_connectivityEntityFacade. Note that because
 * in_connectivityEntityFacade does not contain any metadata there is no type checking
 * performed.
 */
#define in_connectivityEntityFacade(facade) ((in_connectivityEntityFacade)facade)

OS_STRUCT(in_connectivityEntityFacade)
{
    OS_EXTENDS(in_object);
    os_uint32 matchedDcpsEntityCount;
    in_ddsiGuid id;
};

os_boolean
in_connectivityEntityFacadeInit(
    in_connectivityEntityFacade _this,
    in_objectKind kind,
    in_objectDeinitFunc destroy);

void
in_connectivityEntityFacadeDeinit(
    in_object _this);

in_ddsiGuid
in_connectivityEntityFacadeGetGuid(
    in_connectivityEntityFacade _this);

void
in_connectivityEntityFacadeAddMatchedEntity(
    in_connectivityEntityFacade _this);

void
n_connectivityEntityFacadeRemoveMatchedEntity(
    in_connectivityEntityFacade _this);

#if defined (__cplusplus)
}
#endif

#endif /* IN_CONNECTIVITYENTITY_FACADE_H_ */