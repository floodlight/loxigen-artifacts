// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver12;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFActionNiciraResubmitTableVer12 implements OFActionNiciraResubmitTable {
    private static final Logger logger = LoggerFactory.getLogger(OFActionNiciraResubmitTableVer12.class);
    // version: 1.2
    final static byte WIRE_VERSION = 3;
    final static int LENGTH = 16;

        private final static OFPort DEFAULT_PORT = OFPort.IN_PORT;
        private final static TableId DEFAULT_TABLE_ID = TableId.ALL;

    // OF message fields
    private final OFPort port;
    private final TableId tableId;
//
    // Immutable default instance
    final static OFActionNiciraResubmitTableVer12 DEFAULT = new OFActionNiciraResubmitTableVer12(
        DEFAULT_PORT, DEFAULT_TABLE_ID
    );

    // package private constructor - used by readers, builders, and factory
    OFActionNiciraResubmitTableVer12(OFPort port, TableId tableId) {
        if(port == null) {
            throw new NullPointerException("OFActionNiciraResubmitTableVer12: property port cannot be null");
        }
        if(tableId == null) {
            throw new NullPointerException("OFActionNiciraResubmitTableVer12: property tableId cannot be null");
        }
        this.port = port;
        this.tableId = tableId;
    }

    // Accessors for OF message fields
    @Override
    public OFActionType getType() {
        return OFActionType.EXPERIMENTER;
    }

    @Override
    public long getExperimenter() {
        return 0x2320L;
    }

    @Override
    public int getSubtype() {
        return 0xe;
    }

    @Override
    public OFPort getPort() {
        return port;
    }

    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



    public OFActionNiciraResubmitTable.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFActionNiciraResubmitTable.Builder {
        final OFActionNiciraResubmitTableVer12 parentMessage;

        // OF message fields
        private boolean portSet;
        private OFPort port;
        private boolean tableIdSet;
        private TableId tableId;

        BuilderWithParent(OFActionNiciraResubmitTableVer12 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFActionType getType() {
        return OFActionType.EXPERIMENTER;
    }

    @Override
    public long getExperimenter() {
        return 0x2320L;
    }

    @Override
    public int getSubtype() {
        return 0xe;
    }

    @Override
    public OFPort getPort() {
        return port;
    }

    @Override
    public OFActionNiciraResubmitTable.Builder setPort(OFPort port) {
        this.port = port;
        this.portSet = true;
        return this;
    }
    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFActionNiciraResubmitTable.Builder setTableId(TableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



        @Override
        public OFActionNiciraResubmitTable build() {
                OFPort port = this.portSet ? this.port : parentMessage.port;
                if(port == null)
                    throw new NullPointerException("Property port must not be null");
                TableId tableId = this.tableIdSet ? this.tableId : parentMessage.tableId;
                if(tableId == null)
                    throw new NullPointerException("Property tableId must not be null");

                //
                return new OFActionNiciraResubmitTableVer12(
                    port,
                    tableId
                );
        }

    }

    static class Builder implements OFActionNiciraResubmitTable.Builder {
        // OF message fields
        private boolean portSet;
        private OFPort port;
        private boolean tableIdSet;
        private TableId tableId;

    @Override
    public OFActionType getType() {
        return OFActionType.EXPERIMENTER;
    }

    @Override
    public long getExperimenter() {
        return 0x2320L;
    }

    @Override
    public int getSubtype() {
        return 0xe;
    }

    @Override
    public OFPort getPort() {
        return port;
    }

    @Override
    public OFActionNiciraResubmitTable.Builder setPort(OFPort port) {
        this.port = port;
        this.portSet = true;
        return this;
    }
    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFActionNiciraResubmitTable.Builder setTableId(TableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }

//
        @Override
        public OFActionNiciraResubmitTable build() {
            OFPort port = this.portSet ? this.port : DEFAULT_PORT;
            if(port == null)
                throw new NullPointerException("Property port must not be null");
            TableId tableId = this.tableIdSet ? this.tableId : DEFAULT_TABLE_ID;
            if(tableId == null)
                throw new NullPointerException("Property tableId must not be null");


            return new OFActionNiciraResubmitTableVer12(
                    port,
                    tableId
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFActionNiciraResubmitTable> {
        @Override
        public OFActionNiciraResubmitTable readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 65535
            short type = bb.readShort();
            if(type != (short) 0xffff)
                throw new OFParseError("Wrong type: Expected=OFActionType.EXPERIMENTER(65535), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 16)
                throw new OFParseError("Wrong length: Expected=16(16), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            // fixed value property experimenter == 0x2320L
            int experimenter = bb.readInt();
            if(experimenter != 0x2320)
                throw new OFParseError("Wrong experimenter: Expected=0x2320L(0x2320L), got="+experimenter);
            // fixed value property subtype == 0xe
            short subtype = bb.readShort();
            if(subtype != (short) 0xe)
                throw new OFParseError("Wrong subtype: Expected=0xe(0xe), got="+subtype);
            OFPort port = OFPort.read2Bytes(bb);
            TableId tableId = TableId.readByte(bb);
            // pad: 3 bytes
            bb.skipBytes(3);

            OFActionNiciraResubmitTableVer12 actionNiciraResubmitTableVer12 = new OFActionNiciraResubmitTableVer12(
                    port,
                      tableId
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", actionNiciraResubmitTableVer12);
            return actionNiciraResubmitTableVer12;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFActionNiciraResubmitTableVer12Funnel FUNNEL = new OFActionNiciraResubmitTableVer12Funnel();
    static class OFActionNiciraResubmitTableVer12Funnel implements Funnel<OFActionNiciraResubmitTableVer12> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFActionNiciraResubmitTableVer12 message, PrimitiveSink sink) {
            // fixed value property type = 65535
            sink.putShort((short) 0xffff);
            // fixed value property length = 16
            sink.putShort((short) 0x10);
            // fixed value property experimenter = 0x2320L
            sink.putInt(0x2320);
            // fixed value property subtype = 0xe
            sink.putShort((short) 0xe);
            message.port.putTo(sink);
            message.tableId.putTo(sink);
            // skip pad (3 bytes)
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFActionNiciraResubmitTableVer12> {
        @Override
        public void write(ByteBuf bb, OFActionNiciraResubmitTableVer12 message) {
            // fixed value property type = 65535
            bb.writeShort((short) 0xffff);
            // fixed value property length = 16
            bb.writeShort((short) 0x10);
            // fixed value property experimenter = 0x2320L
            bb.writeInt(0x2320);
            // fixed value property subtype = 0xe
            bb.writeShort((short) 0xe);
            message.port.write2Bytes(bb);
            message.tableId.writeByte(bb);
            // pad: 3 bytes
            bb.writeZero(3);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFActionNiciraResubmitTableVer12(");
        b.append("port=").append(port);
        b.append(", ");
        b.append("tableId=").append(tableId);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFActionNiciraResubmitTableVer12 other = (OFActionNiciraResubmitTableVer12) obj;

        if (port == null) {
            if (other.port != null)
                return false;
        } else if (!port.equals(other.port))
            return false;
        if (tableId == null) {
            if (other.tableId != null)
                return false;
        } else if (!tableId.equals(other.tableId))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((port == null) ? 0 : port.hashCode());
        result = prime * result + ((tableId == null) ? 0 : tableId.hashCode());
        return result;
    }

}
