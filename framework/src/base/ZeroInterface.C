/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "ZeroInterface.h"
#include "FEProblem.h"

ZeroInterface::ZeroInterface(const InputParameters & parameters)
  : _zi_feproblem(*parameters.getCheckedPointerParam<FEProblemBase *>("_fe_problem_base")),
    _zi_tid(parameters.get<THREAD_ID>("_tid")),
    _real_zero(_zi_feproblem._real_zero[_zi_tid]),
    _zero(_zi_feproblem._zero[_zi_tid]),
    _grad_zero(_zi_feproblem._grad_zero[_zi_tid]),
    _second_zero(_zi_feproblem._second_zero[_zi_tid]),
    _second_phi_zero(_zi_feproblem._second_phi_zero[_zi_tid])
{
}
