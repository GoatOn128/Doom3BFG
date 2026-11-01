# Build digest

commit: 3059888d4562

- windows-x64-debug: cancelled
- windows-x64-release: failure
- windows-x86-debug: failure
- windows-x86-release: cancelled

## windows-x64-debug

status: cancelled

errors: 238
warnings: 0 in 0 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Dict.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\geometry\DrawVert.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\geometry\JointTransform.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\geometry\Surface.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\geometry\Surface_Patch.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\geometry\Surface_Polytope.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\geometry\Surface_SweptSpline.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\geometry\Winding.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\geometry\TraceModel.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\geometry\Winding2D.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\hashing\CRC32.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\hashing\MD5.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\hashing\MD4.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Heap.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\LangDict.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Lexer.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Lib.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\MapFile.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Angles.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Complex.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Lcp.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Math.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Matrix.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\MatX.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Ode.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Plane.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Pluecker.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Polynomial.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Quat.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Rotation.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Simd.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Simd_SSE.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Simd_Generic.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\Vector.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\math\VecX.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\ParallelJobList.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Parser.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\RectAllocator.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Str.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\sys\sys_assert.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\sys\sys_exceptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\sys\win32\win_crashhandler.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\sys\win32\win_thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Timer.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Token.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Achievements.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Actor.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\AF.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\AFEntity.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\ai\AAS.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\ai\AAS_debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\ai\AAS_pathing.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\ai\AAS_routing.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\ai\AI.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\ai\AI_events.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\ai\AI_pathing.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\ai\AI_Vagary.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\AimAssist.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\anim\Anim.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\anim\Anim_Blend.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\anim\Anim_Testmodel.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\BrittleFracture.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Camera.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Entity.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Fx.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Game_local.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Game_network.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\GameEdit.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\gamesys\Class.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\gamesys\Event.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\gamesys\SaveGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\gamesys\SysCmds.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\gamesys\SysCvar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Grabber.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\IK.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Item.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Leaderboards.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Light.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_HUD.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_PDA.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Scoreboard.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Shell.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_HUD.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_Inventory.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_UserData.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_UserEmails.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_VideoDisks.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Scoreboard.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Bindings.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Browser.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Controls.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Credits.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Dev.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Difficulty.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_GameLobby.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_GameOptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Gamepad.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Leaderboards.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Load.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_MatchSettings.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ModeSelect.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_NewGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_PartyLobby.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Pause.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Playstation.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Resolution.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Root.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Save.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Settings.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Singleplayer.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_SystemOptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Button.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Carousel.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_CommandBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_DynamicList.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Help.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_InfoBox.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_ItemAssignment.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_List.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_LobbyList.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_MenuBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_NavBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_NavButton.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_AudioFiles.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_EmailInbox.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_UserData.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_Objective.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_VideoInfo.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Scrollbar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Shell_SaveInfo.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Misc.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Moveable.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Mover.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\MultiplayerGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Clip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Force.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Constant.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Drag.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Field.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Grab.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Spring.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Actor.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_AF.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Base.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Monster.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Parametric.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Player.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_RigidBody.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Static.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_StaticMulti.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\physics\Push.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Player.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\PlayerIcon.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\PlayerView.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\idlib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Projectile.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Pvs.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\script\Script_Compiler.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\script\Script_Interpreter.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\script\Script_Program.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\script\Script_Thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\SecurityCamera.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\SmokeParticles.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Sound.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Target.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Trigger.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\Weapon.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\Game-D3XP\d3xp\WorldSpawn.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\cm\CollisionModel_contacts.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\cm\CollisionModel_contents.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\cm\CollisionModel_debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\cm\CollisionModel_files.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\cm\CollisionModel_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\cm\CollisionModel_rotate.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\cm\CollisionModel_trace.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\cm\CollisionModel_translate.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\CmdSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Common.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Common_demos.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Common_dialog.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\common_frame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Common_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Common_localize.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Common_menu.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Common_network.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Common_printf.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Common_tools.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Compressor.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Console.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\ConsoleHistory.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\CVarSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DebugGraph.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclAF.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclEntityDef.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclFX.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclParticle.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclPDA.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclSkin.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DeclTable.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\DemoFile.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\EditField.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\EventLoop.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\File_Manifest.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\File_Resource.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\File_SaveGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\File_Zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\FileSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\KeyInput.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\PlayerProfile.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\TokenParser.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\UsercmdGen.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\framework\Zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\AutoRender.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\AutoRenderBink.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\DoomEXE\renderer\BinaryImage.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-debug-msvc\obj\external\external\minizip\zip.cpp.obj

```
C:              150G  120G   31G  80% /c
Collecting scons
  Downloading scons-4.11.1-py3-none-any.whl.metadata (9.2 kB)
Downloading scons-4.11.1-py3-none-any.whl (4.1 MB)
   ---------------------------------------- 4.1/4.1 MB 16.0 MB/s  0:00:00
Installing collected packages: scons
Successfully installed scons-4.11.1
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
Compiling 'neo\external\glad\src\gl.c'
Compiling 'neo\external\miniz\miniz.c'
Compiling 'neo\external\minizip\ioapi.c'
ioapi.c
miniz.c
gl.c
Compiling 'neo\external\minizip\unzip.cpp'
unzip.cpp
Compiling 'neo\external\minizip\zip.cpp'
Compiling 'neo\external\libbinkdec\src\BinkAudio.cpp'
zip.cpp
BinkAudio.cpp
Compiling 'neo\external\libbinkdec\src\BinkDecoder.cpp'
BinkDecoder.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\external\libbinkdec\src\BinkVideo.cpp'
Compiling 'neo\external\libbinkdec\src\BitReader.cpp'
BinkVideo.cpp
BitReader.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\external\external\minizip\unzip.cpp.obj

```
Collecting scons
  Downloading scons-4.11.1-py3-none-any.whl.metadata (9.2 kB)
Downloading scons-4.11.1-py3-none-any.whl (4.1 MB)
   ---------------------------------------- 4.1/4.1 MB 16.0 MB/s  0:00:00
Installing collected packages: scons
Successfully installed scons-4.11.1
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
Compiling 'neo\external\glad\src\gl.c'
Compiling 'neo\external\miniz\miniz.c'
Compiling 'neo\external\minizip\ioapi.c'
ioapi.c
miniz.c
gl.c
Compiling 'neo\external\minizip\unzip.cpp'
unzip.cpp
Compiling 'neo\external\minizip\zip.cpp'
Compiling 'neo\external\libbinkdec\src\BinkAudio.cpp'
zip.cpp
BinkAudio.cpp
Compiling 'neo\external\libbinkdec\src\BinkDecoder.cpp'
BinkDecoder.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\external\libbinkdec\src\BinkVideo.cpp'
Compiling 'neo\external\libbinkdec\src\BitReader.cpp'
BinkVideo.cpp
BitReader.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-debug-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\FileStream.cpp'
Compiling 'neo\external\libbinkdec\src\HuffmanVLC.cpp'
FileStream.cpp
HuffmanVLC.cpp
Compiling 'neo\external\libbinkdec\src\LogError.cpp'
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Compiling 'neo\external\libbinkdec\src\avfft.c'
Compiling 'neo\external\libbinkdec\src\dct.c'
Util.cpp
avfft.c
dct.c
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
Compiling 'neo\external\libbinkdec\src\mdct.c'
dct32.c
fft.c
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Base64.cpp
BitMsg.cpp
Compiling 'neo\idLib\bv\Bounds.cpp'
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Base64.cpp.obj

```
FileStream.cpp
HuffmanVLC.cpp
Compiling 'neo\external\libbinkdec\src\LogError.cpp'
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Compiling 'neo\external\libbinkdec\src\avfft.c'
Compiling 'neo\external\libbinkdec\src\dct.c'
Util.cpp
avfft.c
dct.c
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
Compiling 'neo\external\libbinkdec\src\mdct.c'
dct32.c
fft.c
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Base64.cpp
BitMsg.cpp
Compiling 'neo\idLib\bv\Bounds.cpp'
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\avfft.c'
Compiling 'neo\external\libbinkdec\src\dct.c'
Util.cpp
avfft.c
dct.c
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
Compiling 'neo\external\libbinkdec\src\mdct.c'
dct32.c
fft.c
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Base64.cpp
BitMsg.cpp
Compiling 'neo\idLib\bv\Bounds.cpp'
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Sphere.cpp
CmdArgs.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj

```
dct.c
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
Compiling 'neo\external\libbinkdec\src\mdct.c'
dct32.c
fft.c
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Base64.cpp
BitMsg.cpp
Compiling 'neo\idLib\bv\Bounds.cpp'
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Sphere.cpp
CmdArgs.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj

```
dct32.c
fft.c
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Base64.cpp
BitMsg.cpp
Compiling 'neo\idLib\bv\Bounds.cpp'
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Sphere.cpp
CmdArgs.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Base64.cpp
BitMsg.cpp
Compiling 'neo\idLib\bv\Bounds.cpp'
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Sphere.cpp
CmdArgs.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\idLib\Debug.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CommandLink.cpp.obj

```
Base64.cpp
BitMsg.cpp
Compiling 'neo\idLib\bv\Bounds.cpp'
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Sphere.cpp
CmdArgs.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\idLib\Debug.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Dict.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Debug.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
```

- build\scons\windows-x64-debug-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj

```
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Sphere.cpp
CmdArgs.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\idLib\Debug.cpp'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Dict.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Debug.cpp
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
Dict.cpp
Compiling 'neo\idLib\geometry\DrawVert.cpp'
DrawVert.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-debug-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj] Error 2
```


### warning kinds

## windows-x64-release

status: failure

errors: 421
warnings: 1 in 1 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Dict.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\geometry\DrawVert.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\geometry\JointTransform.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\geometry\Surface_Patch.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\geometry\Surface.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\geometry\Surface_Polytope.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\geometry\Surface_SweptSpline.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\geometry\TraceModel.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\geometry\Winding.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\geometry\Winding2D.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\hashing\CRC32.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\hashing\MD4.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\hashing\MD5.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Heap.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\LangDict.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Lexer.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Lib.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Angles.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\MapFile.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Complex.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Lcp.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Math.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Matrix.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\MatX.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Ode.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Plane.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Pluecker.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Polynomial.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Quat.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Rotation.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Simd.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Simd_Generic.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Simd_SSE.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\Vector.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\math\VecX.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\ParallelJobList.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Parser.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\RectAllocator.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Str.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\sys\sys_assert.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\sys\win32\win_crashhandler.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\sys\sys_exceptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\sys\win32\win_thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Timer.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Token.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Achievements.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Actor.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\AF.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\AFEntity.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\ai\AAS.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\ai\AAS_debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\ai\AAS_pathing.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\ai\AAS_routing.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\ai\AI.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\ai\AI_events.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\ai\AI_pathing.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\ai\AI_Vagary.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\AimAssist.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\anim\Anim.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\anim\Anim_Blend.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\anim\Anim_Testmodel.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\BrittleFracture.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Camera.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Entity.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Fx.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Game_local.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Game_network.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\GameEdit.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\gamesys\Class.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\gamesys\Event.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\gamesys\SaveGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\gamesys\SysCmds.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\gamesys\SysCvar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Grabber.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\IK.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Item.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Leaderboards.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Light.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_HUD.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_PDA.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Scoreboard.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Shell.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_HUD.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_Inventory.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_UserData.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_VideoDisks.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_UserEmails.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Scoreboard.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Bindings.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Browser.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Controls.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Credits.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Dev.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Difficulty.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_GameLobby.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_GameOptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Gamepad.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Leaderboards.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Load.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_MatchSettings.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ModeSelect.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_NewGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_PartyLobby.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Pause.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Playstation.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Resolution.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Root.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Save.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Settings.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Singleplayer.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_SystemOptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Button.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Carousel.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_CommandBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_DynamicList.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Help.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_InfoBox.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_ItemAssignment.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_List.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_LobbyList.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_MenuBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_NavBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_NavButton.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_AudioFiles.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_EmailInbox.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_Objective.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_UserData.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_VideoInfo.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Scrollbar.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Shell_SaveInfo.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Misc.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Moveable.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Mover.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\MultiplayerGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Clip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Force.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Constant.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Drag.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Field.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Grab.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Spring.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Actor.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_AF.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Base.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Parametric.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Monster.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Player.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_RigidBody.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Static.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_StaticMulti.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\physics\Push.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Player.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\PlayerIcon.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\PlayerView.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\idlib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Projectile.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Pvs.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\script\Script_Compiler.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\script\Script_Interpreter.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\script\Script_Program.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\script\Script_Thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\SecurityCamera.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\SmokeParticles.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Sound.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Target.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Trigger.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\Weapon.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\Game-D3XP\d3xp\WorldSpawn.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\cm\CollisionModel_contacts.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\cm\CollisionModel_contents.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\cm\CollisionModel_debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\cm\CollisionModel_files.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\cm\CollisionModel_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\cm\CollisionModel_rotate.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\cm\CollisionModel_trace.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\cm\CollisionModel_translate.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\CmdSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Common.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Common_demos.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Common_dialog.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\common_frame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Common_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Common_localize.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Common_menu.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Common_network.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Common_printf.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Common_tools.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Compressor.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Console.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\ConsoleHistory.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\CVarSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DebugGraph.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclAF.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclEntityDef.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclFX.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclParticle.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclPDA.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclSkin.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DeclTable.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\DemoFile.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\EditField.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\EventLoop.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\File_Manifest.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\File_Resource.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\File_SaveGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\File_Zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\FileSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\KeyInput.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\PlayerProfile.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\TokenParser.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\UsercmdGen.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\framework\Zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\AutoRender.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\AutoRenderBink.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\BinaryImage.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\BufferObject.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Cinematic.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\CinematicBink.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\CinematicRoQ.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Color\ColorSpace.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DeclRenderProgGenerator.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DXT\DXTDecoder.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DXT\DXTEncoder.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\DXT\DXTEncoder_SSE2.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Font.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\GLMatrix.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\GuiModel.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Image_intrinsic.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Image_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Image_process.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Image_program.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ImageManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Interaction.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model_ase.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model_beam.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model_liquid.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model_lwo.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model_ma.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model_md3.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model_md5.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model_prt.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\Model_sprite.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ModelDecal.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ModelManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ModelOverlay.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ParmBlockParser.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderEntity.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderLog.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderProgParm.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderProgs.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld_demo.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\RenderWorld_portals.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ResolutionScale.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\ScreenRect.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_backend_draw.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_frontend_addmodels.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_frontend_deform.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_frontend_guisurf.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_frontend_main.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_frontend_subview.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_trace.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\DoomEXE\renderer\tr_trisurf.cpp.obj] Error 2

### failure context

- build\scons\windows-x64-release-msvc\obj\external\external\minizip\unzip.cpp.obj

```
Filesystem      Size  Used Avail Use% Mounted on
C:              150G  123G   28G  82% /c
Collecting scons
  Downloading scons-4.11.1-py3-none-any.whl.metadata (9.2 kB)
Downloading scons-4.11.1-py3-none-any.whl (4.1 MB)
   ---------------------------------------- 4.1/4.1 MB 16.8 MB/s  0:00:00
Installing collected packages: scons
Successfully installed scons-4.11.1
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
Compiling 'neo\external\glad\src\gl.c'
Compiling 'neo\external\miniz\miniz.c'
Compiling 'neo\external\minizip\ioapi.c'
Compiling 'neo\external\minizip\unzip.cpp'
gl.c
unzip.cpp
miniz.c
ioapi.c
Compiling 'neo\external\minizip\zip.cpp'
zip.cpp
Compiling 'neo\external\libbinkdec\src\BinkAudio.cpp'
BinkAudio.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\external\external\minizip\zip.cpp.obj

```
Filesystem      Size  Used Avail Use% Mounted on
C:              150G  123G   28G  82% /c
Collecting scons
  Downloading scons-4.11.1-py3-none-any.whl.metadata (9.2 kB)
Downloading scons-4.11.1-py3-none-any.whl (4.1 MB)
   ---------------------------------------- 4.1/4.1 MB 16.8 MB/s  0:00:00
Installing collected packages: scons
Successfully installed scons-4.11.1
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
Compiling 'neo\external\glad\src\gl.c'
Compiling 'neo\external\miniz\miniz.c'
Compiling 'neo\external\minizip\ioapi.c'
Compiling 'neo\external\minizip\unzip.cpp'
gl.c
unzip.cpp
miniz.c
ioapi.c
Compiling 'neo\external\minizip\zip.cpp'
zip.cpp
Compiling 'neo\external\libbinkdec\src\BinkAudio.cpp'
BinkAudio.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\FileStream.cpp'
FileStream.cpp
Compiling 'neo\external\libbinkdec\src\HuffmanVLC.cpp'
HuffmanVLC.cpp
Compiling 'neo\external\libbinkdec\src\LogError.cpp'
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Util.cpp
Compiling 'neo\external\libbinkdec\src\avfft.c'
avfft.c
Compiling 'neo\external\libbinkdec\src\dct.c'
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
dct32.c
dct.c
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj

```
FileStream.cpp
Compiling 'neo\external\libbinkdec\src\HuffmanVLC.cpp'
HuffmanVLC.cpp
Compiling 'neo\external\libbinkdec\src\LogError.cpp'
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Util.cpp
Compiling 'neo\external\libbinkdec\src\avfft.c'
avfft.c
Compiling 'neo\external\libbinkdec\src\dct.c'
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
dct32.c
dct.c
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj

```
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Util.cpp
Compiling 'neo\external\libbinkdec\src\avfft.c'
avfft.c
Compiling 'neo\external\libbinkdec\src\dct.c'
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
dct32.c
dct.c
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\idLib\CmdArgs.cpp'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
dct32.c
dct.c
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\idLib\CmdArgs.cpp'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\idLib\CmdArgs.cpp'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\idLib\CmdArgs.cpp'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\idLib\idlib\CommandLink.cpp.obj

```
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\idLib\CmdArgs.cpp'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Debug.cpp'
Compiling 'neo\idLib\Dict.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Debug.cpp
Dict.cpp
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
```

- build\scons\windows-x64-release-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj

```
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\idLib\CmdArgs.cpp'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Debug.cpp'
Compiling 'neo\idLib\Dict.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Debug.cpp
Dict.cpp
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
Compiling 'neo\idLib\geometry\DrawVert.cpp'
DrawVert.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x64-release-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj] Error 2
```


### warning kinds

- [1x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used

## windows-x86-debug

status: failure

errors: 421
warnings: 1 in 1 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\geometry\DrawVert.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Dict.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\geometry\JointTransform.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\geometry\Surface_Patch.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\geometry\Surface.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\geometry\Surface_Polytope.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\geometry\Surface_SweptSpline.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\geometry\TraceModel.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\geometry\Winding.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\geometry\Winding2D.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\hashing\CRC32.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\hashing\MD4.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\hashing\MD5.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Heap.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\LangDict.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Lexer.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Lib.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\MapFile.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Angles.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Complex.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Lcp.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Math.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Matrix.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\MatX.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Ode.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Plane.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Pluecker.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Polynomial.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Quat.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Rotation.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Simd.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Simd_Generic.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Simd_SSE.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\Vector.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\math\VecX.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\ParallelJobList.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Parser.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\RectAllocator.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Str.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\sys\sys_assert.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\sys\sys_exceptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\sys\win32\win_crashhandler.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\sys\win32\win_thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Timer.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Token.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Achievements.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Actor.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\AF.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\AFEntity.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\ai\AAS.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\ai\AAS_debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\ai\AAS_pathing.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\ai\AAS_routing.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\ai\AI.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\ai\AI_events.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\ai\AI_pathing.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\ai\AI_Vagary.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\AimAssist.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\anim\Anim.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\anim\Anim_Blend.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\anim\Anim_Testmodel.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\BrittleFracture.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Camera.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Entity.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Fx.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Game_local.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Game_network.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\GameEdit.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\gamesys\Class.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\gamesys\Event.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\gamesys\SaveGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\gamesys\SysCmds.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\gamesys\SysCvar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Grabber.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\IK.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Item.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Leaderboards.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Light.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_HUD.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_PDA.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Scoreboard.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Shell.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_HUD.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_Inventory.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_UserData.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_UserEmails.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_VideoDisks.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Scoreboard.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Bindings.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Browser.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Controls.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Credits.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Dev.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Difficulty.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_GameLobby.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_GameOptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Gamepad.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Leaderboards.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Load.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_MatchSettings.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ModeSelect.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_NewGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_PartyLobby.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Pause.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Playstation.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Resolution.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Root.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Save.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Settings.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Singleplayer.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_SystemOptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Button.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Carousel.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_CommandBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_DynamicList.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Help.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_InfoBox.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_ItemAssignment.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_List.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_LobbyList.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_MenuBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_NavBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_NavButton.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_AudioFiles.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_EmailInbox.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_Objective.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_UserData.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_VideoInfo.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Scrollbar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Shell_SaveInfo.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Misc.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Moveable.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Mover.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\MultiplayerGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Clip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Force.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Constant.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Drag.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Field.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Grab.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Force_Spring.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Actor.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_AF.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Base.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Monster.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Parametric.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Player.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_RigidBody.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_Static.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Physics_StaticMulti.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\physics\Push.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Player.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\PlayerIcon.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\PlayerView.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\idlib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Projectile.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Pvs.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\script\Script_Compiler.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\script\Script_Interpreter.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\script\Script_Program.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\script\Script_Thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\SecurityCamera.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\SmokeParticles.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Sound.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Target.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Trigger.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\Weapon.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\Game-D3XP\d3xp\WorldSpawn.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\cm\CollisionModel_contents.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\cm\CollisionModel_contacts.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\cm\CollisionModel_debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\cm\CollisionModel_files.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\cm\CollisionModel_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\cm\CollisionModel_rotate.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\cm\CollisionModel_trace.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\cm\CollisionModel_translate.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Common.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\CmdSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Common_demos.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Common_dialog.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\common_frame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Common_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Common_localize.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Common_menu.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Common_network.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Common_printf.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Common_tools.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Compressor.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Console.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\ConsoleHistory.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\CVarSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DebugGraph.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclEntityDef.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclAF.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclFX.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclPDA.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclParticle.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclSkin.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DeclTable.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\DemoFile.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\EditField.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\EventLoop.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\File_Resource.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\File_Manifest.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\File_SaveGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\File_Zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\FileSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\KeyInput.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\PlayerProfile.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\UsercmdGen.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\TokenParser.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\framework\Zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\AutoRender.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\BinaryImage.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\AutoRenderBink.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\BufferObject.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Cinematic.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\CinematicRoQ.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\CinematicBink.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Color\ColorSpace.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DeclRenderProgGenerator.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DXT\DXTDecoder.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DXT\DXTEncoder.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\DXT\DXTEncoder_SSE2.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Font.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\GLMatrix.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\GuiModel.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_files.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_intrinsic.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_process.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Image_program.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ImageManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Interaction.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Material.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_ase.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_beam.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_liquid.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_lwo.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_ma.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md3.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_md5.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_prt.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\Model_sprite.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ModelDecal.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ModelManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ModelOverlay.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_backend.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_GraphicsAPIWrapper.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\OpenGL\gl_Image.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ParmBlock.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ParmBlockParser.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderEntity.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderLog.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderProgParm.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderProgs.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderSystem_init.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld_defs.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld_demo.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\RenderWorld_portals.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ResolutionScale.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\ScreenRect.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_backend_draw.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_backend_rendertools.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_addmodels.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_addlights.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_deform.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_guisurf.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_subview.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_frontend_main.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_trace.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\DoomEXE\renderer\tr_trisurf.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-debug-msvc\obj\external\external\minizip\unzip.cpp.obj

```
Filesystem      Size  Used Avail Use% Mounted on
C:              150G  123G   28G  82% /c
Collecting scons
  Downloading scons-4.11.1-py3-none-any.whl.metadata (9.2 kB)
Downloading scons-4.11.1-py3-none-any.whl (4.1 MB)
   ---------------------------------------- 4.1/4.1 MB 38.6 MB/s  0:00:00
Installing collected packages: scons
Successfully installed scons-4.11.1
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
Compiling 'neo\external\glad\src\gl.c'
Compiling 'neo\external\miniz\miniz.c'
Compiling 'neo\external\minizip\ioapi.c'
Compiling 'neo\external\minizip\unzip.cpp'
ioapi.c
unzip.cpp
miniz.c
gl.c
Compiling 'neo\external\minizip\zip.cpp'
Compiling 'neo\external\libbinkdec\src\BinkAudio.cpp'
zip.cpp
BinkAudio.cpp
Compiling 'neo\external\libbinkdec\src\BinkDecoder.cpp'
BinkDecoder.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\external\libbinkdec\src\BinkVideo.cpp'
Compiling 'neo\external\libbinkdec\src\BitReader.cpp'
scons: *** [build\scons\windows-x86-debug-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\external\external\minizip\zip.cpp.obj

```
C:              150G  123G   28G  82% /c
Collecting scons
  Downloading scons-4.11.1-py3-none-any.whl.metadata (9.2 kB)
Downloading scons-4.11.1-py3-none-any.whl (4.1 MB)
   ---------------------------------------- 4.1/4.1 MB 38.6 MB/s  0:00:00
Installing collected packages: scons
Successfully installed scons-4.11.1
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
Compiling 'neo\external\glad\src\gl.c'
Compiling 'neo\external\miniz\miniz.c'
Compiling 'neo\external\minizip\ioapi.c'
Compiling 'neo\external\minizip\unzip.cpp'
ioapi.c
unzip.cpp
miniz.c
gl.c
Compiling 'neo\external\minizip\zip.cpp'
Compiling 'neo\external\libbinkdec\src\BinkAudio.cpp'
zip.cpp
BinkAudio.cpp
Compiling 'neo\external\libbinkdec\src\BinkDecoder.cpp'
BinkDecoder.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Compiling 'neo\external\libbinkdec\src\BinkVideo.cpp'
Compiling 'neo\external\libbinkdec\src\BitReader.cpp'
scons: *** [build\scons\windows-x86-debug-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
BinkVideo.cpp
scons: *** [build\scons\windows-x86-debug-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\FileStream.cpp'
BitReader.cpp
Compiling 'neo\external\libbinkdec\src\HuffmanVLC.cpp'
FileStream.cpp
HuffmanVLC.cpp
Compiling 'neo\external\libbinkdec\src\LogError.cpp'
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Compiling 'neo\external\libbinkdec\src\avfft.c'
Util.cpp
avfft.c
Compiling 'neo\external\libbinkdec\src\dct.c'
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
dct.c
dct32.c
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
Compiling 'neo\idLib\Base64.cpp'
rdft.c
Base64.cpp
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\LogError.cpp'
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Compiling 'neo\external\libbinkdec\src\avfft.c'
Util.cpp
avfft.c
Compiling 'neo\external\libbinkdec\src\dct.c'
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
dct.c
dct32.c
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
Compiling 'neo\idLib\Base64.cpp'
rdft.c
Base64.cpp
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
Sphere.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj

```
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Compiling 'neo\external\libbinkdec\src\avfft.c'
Util.cpp
avfft.c
Compiling 'neo\external\libbinkdec\src\dct.c'
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
dct.c
dct32.c
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
Compiling 'neo\idLib\Base64.cpp'
rdft.c
Base64.cpp
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
Sphere.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\dct32.c'
Compiling 'neo\external\libbinkdec\src\fft.c'
dct.c
dct32.c
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
Compiling 'neo\idLib\Base64.cpp'
rdft.c
Base64.cpp
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
Sphere.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
Compiling 'neo\idLib\CommandLink.cpp'
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj

```
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
Compiling 'neo\external\libbinkdec\src\rdft.c'
mdct.c
Compiling 'neo\idLib\Base64.cpp'
rdft.c
Base64.cpp
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
Sphere.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
Compiling 'neo\idLib\CommandLink.cpp'
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj

```
Compiling 'neo\idLib\Base64.cpp'
rdft.c
Base64.cpp
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
Sphere.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
Compiling 'neo\idLib\CommandLink.cpp'
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Debug.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Debug.cpp
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\idLib\idlib\CommandLink.cpp.obj

```
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
Sphere.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
Compiling 'neo\idLib\CommandLink.cpp'
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Debug.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Debug.cpp
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
Compiling 'neo\idLib\Dict.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
```

- build\scons\windows-x86-debug-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj

```
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
Sphere.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
Compiling 'neo\idLib\CommandLink.cpp'
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Debug.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Debug.cpp
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
Compiling 'neo\idLib\Dict.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
Compiling 'neo\idLib\geometry\DrawVert.cpp'
Dict.cpp
DrawVert.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-debug-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj] Error 2
```


### warning kinds

- [1x] C4701
  - D:\a\Doom3BFG\Doom3BFG\neo\external\stb\stb_vorbis.h(4849) : warning C4701: potentially uninitialized local variable 'mid' used

## windows-x86-release

status: cancelled

errors: 247
warnings: 0 in 0 kinds

### errors

D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Dict.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\geometry\DrawVert.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\geometry\JointTransform.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\geometry\Surface.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\geometry\Surface_Patch.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\geometry\Surface_Polytope.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\geometry\Surface_SweptSpline.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\geometry\TraceModel.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\geometry\Winding.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\geometry\Winding2D.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\hashing\CRC32.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\hashing\MD4.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\hashing\MD5.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Heap.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\LangDict.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Lexer.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Lib.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\MapFile.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Angles.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Complex.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Lcp.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Math.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Matrix.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\MatX.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Ode.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Plane.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Pluecker.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Polynomial.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Quat.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Rotation.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Simd.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Simd_Generic.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Simd_SSE.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\Vector.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\math\VecX.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\ParallelJobList.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Parser.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\RectAllocator.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Str.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\sys\sys_exceptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\sys\sys_assert.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\sys\win32\win_crashhandler.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\sys\win32\win_thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Timer.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Token.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Achievements.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\AF.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Actor.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\AFEntity.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\ai\AAS.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\ai\AAS_debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\ai\AAS_pathing.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\ai\AAS_routing.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\ai\AI.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\ai\AI_events.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\ai\AI_pathing.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\ai\AI_Vagary.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\AimAssist.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\anim\Anim.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\anim\Anim_Blend.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\anim\Anim_Testmodel.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\BrittleFracture.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Camera.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Entity.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Fx.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Game_local.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Game_network.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\GameEdit.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\gamesys\Class.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\gamesys\Event.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\gamesys\SysCmds.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\gamesys\SaveGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\gamesys\SysCvar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Grabber.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\IK.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Item.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Leaderboards.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Light.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_HUD.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_PDA.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Scoreboard.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuHandler_Shell.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_HUD.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_Inventory.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_UserData.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_UserEmails.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_PDA_VideoDisks.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Browser.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Bindings.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Scoreboard.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ControllerLayout.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Controls.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Dev.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Credits.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Difficulty.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_GameOptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_GameLobby.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Gamepad.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Leaderboards.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Load.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_MatchSettings.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_ModeSelect.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_NewGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_PartyLobby.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Pause.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Playstation.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Resolution.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Root.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Save.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Settings.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_Singleplayer.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuScreen_Shell_SystemOptions.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Button.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Carousel.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_CommandBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_DynamicList.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Help.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_InfoBox.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_ItemAssignment.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_List.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_LobbyList.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_MenuBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_NavButton.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_NavBar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_AudioFiles.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_EmailInbox.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_Objective.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_UserData.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_PDA_VideoInfo.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Shell_SaveInfo.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\menus\MenuWidget_Scrollbar.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Misc.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Moveable.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Mover.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\MultiplayerGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Clip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Force.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Drag.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Constant.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Field.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Grab.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Force_Spring.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Actor.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_AF.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Base.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Monster.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Parametric.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Player.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_RigidBody.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_Static.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Physics_StaticMulti.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\physics\Push.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Player.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\PlayerIcon.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\PlayerView.cpp.obj] Error 2
D:\a\Doom3BFG\Doom3BFG\neo\idlib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Pvs.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Projectile.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\script\Script_Compiler.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\script\Script_Interpreter.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\script\Script_Program.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\script\Script_Thread.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\SecurityCamera.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\SmokeParticles.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Sound.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Target.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Trigger.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\Weapon.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\Game-D3XP\d3xp\WorldSpawn.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\cm\CollisionModel_contacts.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\cm\CollisionModel_contents.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\cm\CollisionModel_debug.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\cm\CollisionModel_files.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\cm\CollisionModel_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\cm\CollisionModel_rotate.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\cm\CollisionModel_trace.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\cm\CollisionModel_translate.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\CmdSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Common.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Common_demos.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Common_dialog.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\common_frame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Common_load.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Common_localize.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Common_menu.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Common_network.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Common_printf.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Common_tools.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Compressor.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Console.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\ConsoleHistory.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\CVarSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DebugGraph.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclAF.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclEntityDef.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclFX.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclManager.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclParticle.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclPDA.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclSkin.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DeclTable.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\DemoFile.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\EditField.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\EventLoop.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\File.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\File_Manifest.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\File_Resource.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\File_SaveGame.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\File_Zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\FileSystem.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\KeyInput.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\PlayerProfile.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\precompiled.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\TokenParser.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\UsercmdGen.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\framework\Zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\AutoRender.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\AutoRenderBink.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\BinaryImage.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\BufferObject.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\CinematicBink.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\Cinematic.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\CinematicRoQ.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\Color\ColorSpace.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\DeclRenderProg.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\DeclRenderProgGenerator.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\DXT\DXTDecoder.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\DoomEXE\renderer\DXT\DXTEncoder.cpp.obj] Error 2

### failure context

- build\scons\windows-x86-release-msvc\obj\external\external\minizip\zip.cpp.obj

```
Filesystem      Size  Used Avail Use% Mounted on
C:              150G  120G   31G  80% /c
Collecting scons
  Downloading scons-4.11.1-py3-none-any.whl.metadata (9.2 kB)
Downloading scons-4.11.1-py3-none-any.whl (4.1 MB)
   ---------------------------------------- 4.1/4.1 MB 13.0 MB/s  0:00:00
Installing collected packages: scons
Successfully installed scons-4.11.1
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
Compiling 'neo\external\glad\src\gl.c'
Compiling 'neo\external\miniz\miniz.c'
Compiling 'neo\external\minizip\ioapi.c'
gl.c
miniz.c
ioapi.c
Compiling 'neo\external\minizip\unzip.cpp'
unzip.cpp
Compiling 'neo\external\minizip\zip.cpp'
zip.cpp
Compiling 'neo\external\libbinkdec\src\BinkAudio.cpp'
BinkAudio.cpp
Compiling 'neo\external\libbinkdec\src\BinkDecoder.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
BinkDecoder.cpp
scons: *** [build\scons\windows-x86-release-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\external\external\minizip\unzip.cpp.obj

```
Filesystem      Size  Used Avail Use% Mounted on
C:              150G  120G   31G  80% /c
Collecting scons
  Downloading scons-4.11.1-py3-none-any.whl.metadata (9.2 kB)
Downloading scons-4.11.1-py3-none-any.whl (4.1 MB)
   ---------------------------------------- 4.1/4.1 MB 13.0 MB/s  0:00:00
Installing collected packages: scons
Successfully installed scons-4.11.1
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
Compiling 'neo\external\glad\src\gl.c'
Compiling 'neo\external\miniz\miniz.c'
Compiling 'neo\external\minizip\ioapi.c'
gl.c
miniz.c
ioapi.c
Compiling 'neo\external\minizip\unzip.cpp'
unzip.cpp
Compiling 'neo\external\minizip\zip.cpp'
zip.cpp
Compiling 'neo\external\libbinkdec\src\BinkAudio.cpp'
BinkAudio.cpp
Compiling 'neo\external\libbinkdec\src\BinkDecoder.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
BinkDecoder.cpp
scons: *** [build\scons\windows-x86-release-msvc\obj\external\external\minizip\zip.cpp.obj] Error 2
scons: *** [build\scons\windows-x86-release-msvc\obj\external\external\minizip\unzip.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\FileStream.cpp'
FileStream.cpp
Compiling 'neo\external\libbinkdec\src\HuffmanVLC.cpp'
HuffmanVLC.cpp
Compiling 'neo\external\libbinkdec\src\LogError.cpp'
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Util.cpp
Compiling 'neo\external\libbinkdec\src\avfft.c'
Compiling 'neo\external\libbinkdec\src\dct.c'
avfft.c
dct.c
Compiling 'neo\external\libbinkdec\src\dct32.c'
dct32.c
Compiling 'neo\external\libbinkdec\src\fft.c'
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\HuffmanVLC.cpp'
HuffmanVLC.cpp
Compiling 'neo\external\libbinkdec\src\LogError.cpp'
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Util.cpp
Compiling 'neo\external\libbinkdec\src\avfft.c'
Compiling 'neo\external\libbinkdec\src\dct.c'
avfft.c
dct.c
Compiling 'neo\external\libbinkdec\src\dct32.c'
dct32.c
Compiling 'neo\external\libbinkdec\src\fft.c'
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj

```
LogError.cpp
Compiling 'neo\external\libbinkdec\src\Util.cpp'
Util.cpp
Compiling 'neo\external\libbinkdec\src\avfft.c'
Compiling 'neo\external\libbinkdec\src\dct.c'
avfft.c
dct.c
Compiling 'neo\external\libbinkdec\src\dct32.c'
dct32.c
Compiling 'neo\external\libbinkdec\src\fft.c'
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj

```
dct.c
Compiling 'neo\external\libbinkdec\src\dct32.c'
dct32.c
Compiling 'neo\external\libbinkdec\src\fft.c'
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj

```
fft.c
Compiling 'neo\external\libbinkdec\src\mdct.c'
mdct.c
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj

```
Compiling 'neo\external\libbinkdec\src\rdft.c'
rdft.c
Compiling 'neo\idLib\Base64.cpp'
Compiling 'neo\idLib\BitMsg.cpp'
Compiling 'neo\idLib\bv\Bounds.cpp'
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Debug.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\idLib\idlib\CommandLink.cpp.obj

```
Base64.cpp
BitMsg.cpp
Bounds.cpp
Compiling 'neo\idLib\bv\Box.cpp'
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Debug.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
Debug.cpp
Compiling 'neo\idLib\Dict.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Dict.cpp
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
```

- build\scons\windows-x86-release-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj

```
Box.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\Base64.cpp.obj] Error 2
Compiling 'neo\idLib\bv\Sphere.cpp'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\BitMsg.cpp.obj] Error 2
Compiling 'neo\idLib\CmdArgs.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Bounds.cpp.obj] Error 2
Compiling 'neo\idLib\CommandLink.cpp'
Sphere.cpp
CmdArgs.cpp
CommandLink.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Box.cpp.obj] Error 2
Compiling 'neo\idLib\containers\HashIndex.cpp'
HashIndex.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\bv\Sphere.cpp.obj] Error 2
Compiling 'neo\idLib\Debug.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\CmdArgs.cpp.obj] Error 2
Debug.cpp
Compiling 'neo\idLib\Dict.cpp'
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
Dict.cpp
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\CommandLink.cpp.obj] Error 2
Compiling 'neo\idLib\geometry\DrawVert.cpp'
DrawVert.cpp
D:\a\Doom3BFG\Doom3BFG\neo\idLib\../renderer/OpenGL/qgl.h(209): fatal error C1070: mismatched #if/#endif pair in file 'D:\a\Doom3BFG\Doom3BFG\neo\renderer\OpenGL\qgl.h'
scons: *** [build\scons\windows-x86-release-msvc\obj\idLib\idlib\containers\HashIndex.cpp.obj] Error 2
```


### warning kinds

