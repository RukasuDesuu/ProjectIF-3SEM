from typing import List
from ..BaseService import BaseService
from bd.Models.Models import TensaoModel

class TensaoService(BaseService):
    def __init__(self) -> None:
        super().__init__(TensaoModel)

#SELECT cod_v FROM v WHERE v = 220 AND isAC = 1
    def getCodVbyV (self, v:int, isAC:bool):
        query = self._session.query(TensaoModel).filter(TensaoModel.v == v, TensaoModel.isAc== isAC)
        return query.all()
