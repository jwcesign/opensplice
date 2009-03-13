#include <gapi.h>
#include "ccpp_ReadCondition_impl.h"
#include "ccpp_Utils.h"
#include "os_report.h"

DDS::ReadCondition_impl::ReadCondition_impl( 
    gapi_readCondition handle
) : DDS::Condition_impl(handle)
{
  os_mutexAttr mutexAttr = { OS_SCOPE_PRIVATE };
  if (os_mutexInit(&rc_mutex, &mutexAttr) != os_resultSuccess)
  {
    OS_REPORT(OS_ERROR, "CCPP", 0, "Unable to create mutex");
  }
}

DDS::ReadCondition_impl::~ReadCondition_impl()
{
  if (os_mutexDestroy(&rc_mutex) != os_resultSuccess)
  {
    OS_REPORT(OS_ERROR, "CCPP", 0, "Unable to destroy mutex");
  }
}

DDS::SampleStateMask DDS::ReadCondition_impl::get_sample_state_mask (
) THROW_ORB_EXCEPTIONS 
{
  return gapi_readCondition_get_sample_state_mask(_gapi_self);
}
    
DDS::ViewStateMask DDS::ReadCondition_impl::get_view_state_mask (
) THROW_ORB_EXCEPTIONS 
{
  return gapi_readCondition_get_view_state_mask(_gapi_self);
}
    
DDS::InstanceStateMask DDS::ReadCondition_impl::get_instance_state_mask (
) THROW_ORB_EXCEPTIONS 
{
  return gapi_readCondition_get_instance_state_mask(_gapi_self);
}
    
DDS::DataReader_ptr DDS::ReadCondition_impl::get_datareader (
) THROW_ORB_EXCEPTIONS 
{
  gapi_dataReader handle = NULL;
  DDS::DataReader_ptr dataReader = NULL;

  handle = gapi_readCondition_get_datareader(_gapi_self);
  if (handle)
  {
    ccpp_UserData_ptr drUD = NULL;
    drUD = reinterpret_cast<ccpp_UserData_ptr>(gapi_object_get_user_data(handle));
    if (drUD)
    {
      dataReader = dynamic_cast<DDS::DataReader_ptr>(drUD->ccpp_object);
      if (dataReader)
      {
        DDS::DataReader::_duplicate(dataReader);
      }
      else
      {
        OS_REPORT(OS_ERROR, "CCPP", 0, "Invalid Data Reader");
      }
    }
    else
    {
      OS_REPORT(OS_ERROR, "CCPP", 0, "Unable to obtain userdata");
    }
  }
  return dataReader;
}
