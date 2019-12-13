#define EFL_BETA_API_SUPPORT 1
 
#include <Eina.h>
#include <Elementary.h>
#include <Efl_Ui.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

Eo *win, *box, *table, *xprsText, *rsltText;

static void cb_efl_exit(void *data EINA_UNUSED, const Efl_Event *event EINA_UNUSED) {
   efl_exit(0);
}

static void cb_xprs_add_char(void *data EINA_UNUSED, const Efl_Event *event) {
   char strBuffer[64] = {0};
   snprintf(strBuffer, 64, "%s%s", efl_text_get(xprsText), efl_text_get(event->object));
   efl_text_markup_set(xprsText, strBuffer);
}

static double eval_xprs(char *xprsString) {
   return 0.0;
}

EAPI_MAIN void efl_main(void *data EINA_UNUSED, const Efl_Event *ev EINA_UNUSED) {
   win = efl_add(EFL_UI_WIN_CLASS, efl_main_loop_get(),
                 efl_ui_win_type_set(efl_added, EFL_UI_WIN_TYPE_BASIC),
                 efl_ui_win_autodel_set(efl_added, EINA_TRUE),
                 efl_ui_win_borderless_set(efl_added, EINA_TRUE),
                 efl_event_callback_add(efl_added, EFL_UI_WIN_EVENT_DELETE_REQUEST, cb_efl_exit, NULL));
 
   box = efl_add(EFL_UI_BOX_CLASS, win,
                 efl_content_set(win, efl_added));

   xprsText = efl_add(EFL_UI_TEXT_CLASS, box,
                     efl_gfx_hint_weight_set(efl_added, 1.0, 0.3),
                     efl_text_font_set(efl_added, "monospace", 64),
                     efl_text_markup_set(efl_added, "1234.5678"),
                     efl_pack(box, efl_added));

   rsltText = efl_add(EFL_UI_TEXT_CLASS, box,
                     efl_text_markup_set(efl_added, "0.0"),
                     efl_gfx_hint_weight_set(efl_added, 1.0, 0.2),
                     efl_gfx_hint_align_set(efl_added, 1.0, 0.5),
                     efl_pack(box, efl_added));

   table = efl_add(EFL_UI_TABLE_STATIC_CLASS, box,
                  efl_pack_table_size_set(efl_added, 4, 4),
                  efl_pack(box, efl_added));

   for(int i = 0; i < 9; ++i) {
      char strNum[12] = {};
      sprintf(strNum, "%d", i + 1);
      efl_add(EFL_UI_BUTTON_CLASS, table,
            efl_text_set(efl_added, strNum),
            efl_pack_table(table, efl_added, i % 3, 2 - i / 3, 1, 1),
            efl_event_callback_add(efl_added, EFL_UI_EVENT_CLICKED, cb_xprs_add_char, efl_added)); // TODO: add proper callback
   }
}

EFL_MAIN()