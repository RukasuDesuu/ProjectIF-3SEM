
#pip install PySimpleGUI
import math
import re
from typing import List
import PySimpleGUI as sg

from bd.Core.Services.ContatoraService.ContatoraService import ContatoraService
from bd.Core.Services.ReleModelService.ReleModelService import ReleModelService
from bd.Core.Services.ReleService.ReleService import ReleService
from bd.Core.Services.TensaoService.TensaoService import TensaoService
from bd.Models.Models import ContatoraModel, ReleModel, ReleCod

contatoraService: ContatoraService = ContatoraService()
releService: ReleService = ReleService()
tensaoService: TensaoService = TensaoService()
releModelService: ReleModelService = ReleModelService()

def cadastro():

    infoMotorlbl = sg.Text("Informações do Motor", key = '-OUT-', font=('rial Bold', 35), expand_x=True, justification='center')
    #Tensao
    tensaolbl = sg.Text("Tensao:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    tensaotxt = sg.Input('', enable_events=True, key='-TENSAO-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Fator de Servico
    fslbl = sg.Text("Fator de Servico (FS):", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    fstxt = sg.Input('', enable_events=True, key='-FS-', font=('Arial Bold', 20), expand_x=True, justification='left') 
    
    #Potencia
    potlbl = sg.Text("Potencia:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    pottxt = sg.Input('', enable_events=True, key='-POT-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Corrente Nominal
    inlbl = sg.Text("Corrente Nominal (IN):", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    intxt = sg.Input('', enable_events=True, key='-IN-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Ip/In
    ipinlbl = sg.Text("Ip/In:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    ipintxt = sg.Input('', enable_events=True, key='-IPIN-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    infoProjetolbl = sg.Text("Informações do Projeto", key = '-OUT-', font=('rial Bold', 35), expand_x=True, justification='center')
    #Contatos Abertos
    CAlbl = sg.Text("Contatos Abertos:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    CAspn = sg.Spin([0,1,2,3,4],initial_value=0, readonly=True,  size=15, enable_events=True, key='-CA-')

    #Contatos Fechados
    CFlbl = sg.Text("Contatos Fechados:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    CFspn = sg.Spin([0,1,2,3,4],initial_value=0, readonly=True,  size=15, enable_events=True, key='-CF-')

    #Tipo de Corrente
    isAClbl = sg.Text("E corrente alternada? (0 = DC, 1 = AC):", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    isACsldr = sg.Slider(range=(0, 1), default_value=0,expand_x=True, enable_events=True, orientation='horizontal', key='-isAC-')

    #Botao Calcular
    Calcbtn = sg.Button('Dimensionar')

    layout = [[infoMotorlbl],
            [tensaolbl, tensaotxt], 
            [fslbl, fstxt], [potlbl, pottxt],
            [inlbl, intxt], [ipinlbl, ipintxt],
            [infoProjetolbl],
            [CAlbl, CAspn], 
            [CFlbl, CFspn], 
            [isAClbl], [isACsldr],
            [Calcbtn]]
    
    window = sg.Window('Input Demo', layout, size=(900, 700), element_justification='c')


    #loop
    while True:
        event, values = window.read()
        print(event, values)
        if event == 'Dimensionar':
            tensao = int(values['-TENSAO-'])
            pot = float(values['-POT-'])
            fs = float(values['-FS-'])
            inom = float(values['-IN-'])
            ipin = float(values['-IPIN-'])
            nca = values['-CA-']
            ncf = values['-CF-']
            isac = values['-isAC-'];
            
            #Contatora
            iminc = inom*1.1

            #Relé Sobrecarga
            ifrt = 0
            if(fs<1.15):
                ifrt = inom*1.15
            elif (fs>=1.15):
                ifrt = inom*1.25

            #if (imax>ifrt AND imin<ifrt):
            #    det1=imax-ifrt
            #    det2=imin-ifrt
            #    det=det1+det2

            id = (ifrt/(pot*3))
            idR = math.ceil(id)
            releObj: ReleModel = releModelService.get_by_id(idR)
            releM = releObj.modelo
 
            contats:List[ContatoraModel] = contatoraService.get_all()
            if (nca+ncf > 4):
                sg.popup_ok_cancel("Erro!", "contatos abertos + fechados deve ser menor que 4",  title="Error")
            listContatora = []
            listRelesRange = []
            listTensao = []
            listContatoraResul = []
            for contatora in contats:
                for contato in contatora.contatos:
                    if (contato.aberto == nca and contato.fechado == ncf):
                        listContatora.append(contatora.modelo)
                        
        
            for contatora in listContatora:
                valorModelo = re.sub(r'\D', '', contatora)
                if (iminc <= float(valorModelo)):
                    listContatoraResul.append(contatora)
            
            codV = tensaoService.getCodVbyV(tensao, isac)
            
            sg.popup_ok_cancel("Resultado:", "Rele: " + releM + ", ".join(map(str,listRelesRange)), "Contatora: " + ", ".join(str(x)+"-"+str(nca)+str(ncf)+"30" for x in listContatoraResul), "Codigo da Tensao: " + ", ".join(str(x.cod_v)for x in codV) ,  title="Resultado")

        if event == sg.WIN_CLOSED or event == 'Exit':
            break
cadastro()
