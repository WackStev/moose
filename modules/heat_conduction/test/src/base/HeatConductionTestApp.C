#include "HeatConductionTestApp.h"
#include "HeatConductionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<HeatConductionTestApp>()
{
  InputParameters params = validParams<HeatConductionApp>();
  return params;
}

HeatConductionTestApp::HeatConductionTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  HeatConductionApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  HeatConductionApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    HeatConductionTestApp::registerObjects(_factory);
    HeatConductionTestApp::associateSyntax(_syntax, _action_factory);
  }
}

HeatConductionTestApp::~HeatConductionTestApp() {}

// External entry point for dynamic application loading
extern "C" void
HeatConductionTestApp__registerApps()
{
  HeatConductionTestApp::registerApps();
}
void
HeatConductionTestApp::registerApps()
{
  registerApp(HeatConductionApp);
  registerApp(HeatConductionTestApp);
}

// External entry point for dynamic object registration
extern "C" void
HeatConductionTestApp__registerObjects(Factory & factory)
{
  HeatConductionTestApp::registerObjects(factory);
}
void
HeatConductionTestApp::registerObjects(Factory & /*factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
HeatConductionTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  HeatConductionTestApp::associateSyntax(syntax, action_factory);
}
void
HeatConductionTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
