////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////

#include <Prime/Engine.h>
#include <Prime/Graphics/Graphics.h>
#include <Prime/Font/Font.h>

using namespace Prime;

////////////////////////////////////////////////////////////////////////////////
// Entry
////////////////////////////////////////////////////////////////////////////////

int main(int argc, const char* const* argv) {
  // Init engine.
  Engine& engine = PxEngine;

  // Load font.
  refptr font = new Font();

  GetContent("data/Font/NotoSansCJKtc-Regular.otf", {{"size", 36.0f}}, [=](Content* content) {
    font->SetContent(content);
  });

  // Load shaders.
  refptr texProgram = DeviceProgram::Create("data/Shader/Tex/Tex.vsh", "data/Shader/Tex/Tex.fsh");

  ////////////////////////////////////////
  // Main Loop
  ////////////////////////////////////////

  Graphics& g = PxGraphics;

  g.ShowScreen();
  g.program = texProgram;

  engine.Start();
  while(engine.IsRunning()) {
    engine.StartFrame();

    g.ClearScreen();
    g.model.LoadTranslation(g.GetScreenW() * 0.5f, g.GetScreenH() * 0.5f);

    font->Draw("Hello, World!", AlignCenter);

    engine.EndFrame();
  }

  return 0;
}
