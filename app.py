import PySimpleGUI as psg
l1 = psg.Text('Type here', key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='center')
t1 = psg.Input('', enable_events=True, key='-INPUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
b1 = psg.Button('Ok', key='-OK-', font=('Arial Bold', 20))
b2 = psg.Button('Exit', font=('Arial Bold', 20))
layout = [[l1], [t1], [b1, b2]]
window = psg.Window('Input Demo', layout, size=(750, 150))
while True:
   event, values = window.read()
   print(event, values)
   if event == '-INPUT-':
      if values['-INPUT-'][-1] not in ('0123456789'):
         psg.popup("Only digits allowed")
         window['-INPUT-'].update(values['-INPUT-'][:-1])
   if event == psg.WIN_CLOSED or event == 'Exit':
      break
window.close()