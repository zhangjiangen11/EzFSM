#include "register_types.hpp"

#include "state_input.hpp"
#include "state.hpp"
#include "state_machine.hpp"
#include "state_transition.hpp"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

void initialize_state(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

    GDREGISTER_CLASS(godot::ez_fsm::StateMachine);
	GDREGISTER_CLASS(godot::ez_fsm::State);
    GDREGISTER_CLASS(godot::ez_fsm::StateInput);
    GDREGISTER_CLASS(godot::ez_fsm::StateTransition);
}

void uninitialize_state(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
    // Initialization.
    GDExtensionBool GDE_EXPORT ez_fsm_init(
            GDExtensionInterfaceGetProcAddress p_get_proc_address, 
            const GDExtensionClassLibraryPtr p_library, 
            GDExtensionInitialization *r_initialization) {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initialize_state);
        init_obj.register_terminator(uninitialize_state);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }

}