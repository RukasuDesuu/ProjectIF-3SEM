from typing import List
from ..BaseService import BaseService
from bd.Models.Models import ReleCod

class ReleService(BaseService):
    def __init__(self) -> None:
        super().__init__(ReleCod)

    def GetReleByMinMax(self, ifrt:float)->List[ReleCod]:
        query = self._session.query(ReleCod).filter(ReleCod.imin <= ifrt, ReleCod.imax >= ifrt)
        return query.all()
    
    #SELECT Imin, Imax FROM rele_cod WHERE Imin < ifrt AND Imax > ifrt
    #x = releService.GetReleByMinMax(ifrt)
    #for rele in contatora.reles.releCod:
                #    if (rele.imax <= x[0].imax and rele.imin >= x[0].imin):
                #        listRelesRange.append(rele)