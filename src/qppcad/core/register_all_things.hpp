#ifndef QPPCAD_REGISTER_ALL_THINGS_THING
#define QPPCAD_REGISTER_ALL_THINGS_THING

#include <qppcad/core/qppcad.hpp>
#include <qppcad/ws_item/ws_item_behaviour_manager.hpp>

namespace qpp {

  namespace cad {

    struct registration_helper_t {

        template<typename T>
        static void reg_ws_item_fbr(ws_item_behaviour_manager_t *bhv_mgr) {
          bhv_mgr->reg_item_fbr(T::get_type_static(),
                                [](){return std::make_shared<T>();});
        }

        template<typename T, typename U>
        static void reg_ws_item_obj_insp_fbr(ws_item_behaviour_manager_t *bhv_mgr) {
          bhv_mgr->reg_obj_insp_fbr(T::get_type_static(),
                                    [](){return std::make_shared<U>();});
        }

        template<typename T, typename U>
        static void reg_ws_item_ext_edt_fbr(size_t editor_order,
                                            std::string editor_name,
                                            ws_item_behaviour_manager_t *bhv_mgr) {
          bhv_mgr->reg_ext_editor_fbr(T::get_type_static(),
                                      editor_order,
                                      editor_name,
                                      [](){return std::make_shared<U>();});
        }

        static void reg_ws_item_fbr(ws_item_behaviour_manager_t *bhv_mgr);
        static void reg_ws_item_obj_insp(ws_item_behaviour_manager_t *bhv_mgr);
        static void reg_ws_item_ext_edt(ws_item_behaviour_manager_t *bhv_mgr);
        static void reg_ws_item_io_bhv(ws_item_behaviour_manager_t *bhv_mgr);

        template<typename T, typename U>
        static void reg_ws_item_tool(std::string _full_name,
                                     size_t _g_hash,
                                     ws_item_behaviour_manager_t *bhv_mgr,
                                     bool _item_required = true) {
          bhv_mgr->reg_tool(_full_name,
                            _g_hash,
                            U::get_type_static(),
                            _item_required,
                            [](){return std::make_shared<T>();});
        }

        static void reg_ws_item_tools(ws_item_behaviour_manager_t *bhv_mgr);

    };

  } // namespace qpp::cad

} // namespace qpp

#endif
