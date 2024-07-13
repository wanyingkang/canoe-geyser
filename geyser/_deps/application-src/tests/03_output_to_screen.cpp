// C/C++
#include <iostream>

// application
#include <application/application.hpp>

void func2() {
  Application::Logger app("B");

  app->Log("First step");
  app->Log("Second step");
}

void func1() {
  Application::Logger app("A");

  app->Log("First step");
  app->Log("Second step");

  func2();
}

int main(int argc, char **argv) {
  Application::Start(argc, argv);

  func1();

  Application::Destroy();
}
